//! The real ESTI E1868 USB-over-IP transport (TCP 4660).
//!
//! This implements the reverse-engineered wire format end to end: the
//! **response / receive** side (server → client framing, opcode dispatch,
//! session-size latching), the SeqNum allocator, and the **request / transmit**
//! side — control transfers ([`build_control_request`]), bulk transfers
//! ([`build_bulk_request`]) and the session claim ([`build_claim`]) — all decoded
//! from the GenHC.sys static analysis and corroborated by live captures.
//!
//! See `notes/genhc_protocol.md` (owned by the protocol-RE effort) for the
//! authoritative spec. Section references below point at it.
//!
//! Shape:
//!   * `connect()` opens a `tokio::net::TcpStream` to `<ip>:<port>` (default
//!     4660), sends the 116-byte `0x0A` session claim, reads the `0x0B` ack to
//!     latch the session frame size, and spawns a `0x12` keep-alive task (notes
//!     §10.1). The claim is REQUIRED — without it the server drops the link after
//!     one transfer.
//!   * `set_line_coding` builds the PL2303 `SET_LINE_CODING` SETUP packet (via
//!     [`crate::pl2303`]), hands it to [`build_control_request`], and awaits the
//!     completion keyed by SeqNum. Every request frame is zero-padded to the
//!     session frame size before being sent.
//!   * `read`/`write` move bulk-endpoint serial data via [`build_bulk_request`],
//!     segmented into `frame_size - 0x30` payload chunks.

use std::net::SocketAddr;
use std::sync::atomic::{AtomicU16, Ordering};
use std::sync::Arc;
use std::time::Duration;

use tokio::io::{AsyncRead, AsyncReadExt, AsyncWriteExt};
use tokio::net::tcp::{OwnedReadHalf, OwnedWriteHalf};
use tokio::net::TcpStream;
use tokio::sync::Mutex;
use tokio::task::JoinHandle;

use super::{LineCoding, Transport, TransportError};
use crate::pl2303;

/// Default TCP port for the ESTI USB-over-IP channel (0x1234).
pub const DEFAULT_PORT: u16 = 4660;

/// Fixed response-header length (notes §2; GenHC `GetDataFromTDI` @0x204e0 reads
/// exactly `0x20` bytes before parsing the length field): 32 bytes.
pub const HEADER_LEN: usize = 0x20;

/// `"UNT$"` frame signature at response offset 0x00 (dword `0x24544E55`). The
/// completion handler (`FUN_0001ca80`) rejects any frame whose first four bytes
/// are not this magic, so the parser validates it up front.
pub const MAGIC: [u8; 4] = *b"UNT$";

/// Length of the echoed 8-byte USB SETUP packet that a control data-completion
/// response carries at resp 0x20..0x27, immediately before the transfer DATA.
pub const SETUP_ECHO_LEN: usize = 8;

/// Offset of the control-transfer DATA payload inside a response frame
/// (`HEADER_LEN + SETUP_ECHO_LEN` = 0x28). The 8 bytes at 0x20..0x27 are the
/// echoed SETUP packet; the real USB data begins here.
pub const DATA_OFFSET: usize = HEADER_LEN + SETUP_ECHO_LEN;

/// Offset of the **bulk / interrupt** transfer DATA inside a response frame.
/// Bulk transfers have no SETUP stage, so there is no 8-byte echo in the reply:
/// the data begins immediately after the 32-byte header, at `HEADER_LEN` (0x20)
/// — i.e. 8 bytes earlier than a control completion (`DATA_OFFSET` = 0x28).
// LIVE-UNCONFIRMED (0x20 inferred; verify live)
pub const BULK_DATA_OFFSET: usize = HEADER_LEN;

/// How far into a [`Frame::payload`] (the bytes past the 32-byte header) the USB
/// DATA stage begins, per transfer kind. Control replies carry an echoed 8-byte
/// SETUP first (`SETUP_ECHO_LEN`); bulk replies carry none (`0`).
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum TransferKind {
    /// Control transfer: reply data starts at response 0x28 (payload offset 8).
    Control,
    /// Bulk / interrupt transfer: reply data starts at response 0x20 (payload
    /// offset 0).
    // LIVE-UNCONFIRMED (0x20 inferred; verify live)
    Bulk,
}

impl TransferKind {
    /// Byte offset of the DATA stage *within [`Frame::payload`]* for this kind:
    /// `8` for control (skip the echoed SETUP), `0` for bulk.
    pub fn payload_data_offset(self) -> usize {
        match self {
            TransferKind::Control => SETUP_ECHO_LEN,
            TransferKind::Bulk => 0,
        }
    }

    /// Byte offset of the DATA stage within the *whole response frame*
    /// ([`DATA_OFFSET`] = 0x28 for control, [`BULK_DATA_OFFSET`] = 0x20 for bulk).
    pub fn frame_data_offset(self) -> usize {
        HEADER_LEN + self.payload_data_offset()
    }
}

/// Maximum single Rx frame the kernel driver buffers (notes §2/§6): 1460 bytes
/// (one Ethernet MSS). This is also the default send-frame size latched at
/// `ctx+0x2000` (GenHC device-create @0x14fxx writes `0x5b4` there). Payloads
/// larger than this are read by looping; this constant does **not** cap
/// [`read_frame`].
pub const MAX_RX_FRAME: usize = 0x5b4;

// --- Response opcode groups (byte @ header+0x07, notes §2 / §6) --------------

/// Data-carrying completion opcodes: the payload is the transfer result.
pub const OPCODES_DATA: [u8; 7] = [0x01, 0x03, 0x05, 0x09, 0x0F, 0x17, 0x29];
/// Control/ack opcodes: carry a status byte and wake the pending request.
pub const OPCODES_ACK: [u8; 3] = [0x0B, 0x1D, 0x1F];
/// Session/frame-size ack opcodes: latch the BE word @+0x12 as the send-frame
/// size (stored by the driver at `ctx+0x2000`, notes §4).
pub const OPCODES_SIZE: [u8; 2] = [0x0A, 0x1C];

/// Classification of a response opcode.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum OpcodeClass {
    /// Data-carrying completion (`OPCODES_DATA`).
    Data,
    /// Control/ack that wakes a waiter (`OPCODES_ACK`).
    Ack,
    /// Session/frame-size ack (`OPCODES_SIZE`).
    SessionSize,
    /// Unrecognized opcode.
    Unknown,
}

/// Classify a response opcode byte (header offset 0x07).
pub fn classify_opcode(opcode: u8) -> OpcodeClass {
    if OPCODES_DATA.contains(&opcode) {
        OpcodeClass::Data
    } else if OPCODES_ACK.contains(&opcode) {
        OpcodeClass::Ack
    } else if OPCODES_SIZE.contains(&opcode) {
        OpcodeClass::SessionSize
    } else {
        OpcodeClass::Unknown
    }
}

/// Parsed 32-byte response header (server → client).
///
/// The real reply to a proper request is itself a `"UNT$"`-framed descriptor —
/// the request descriptor minus its 16-byte placeholder prefix (so every request
/// field shifts down by 0x10). Layout confirmed against `GetDataFromTDI`
/// (`FUN_000204e0` @0x204e0) and the ground-truth `raw/getdesc_response.bin`:
///   * `"UNT$"` magic @0x00 (validated by the completion handler `FUN_0001ca80`,
///     `*param_2 != 0x24544e55`);
///   * `payload_len` BE u16 @0x04 (`movzx eax,[rsi+4]; ror ax,8`; total frame =
///     `0x20 + payload_len`);
///   * dispatch `opcode` byte @0x07 (GenHC switches on this byte);
///   * `seq` LE u16 @0x08 (`*(u16*)(param_2+8)`);
///   * echoed request `command` byte @0x0C (`0x33` ctrl-IN in the oracle);
///   * `device_index` @0x10, `value` BE @0x12 (session size for 0x0A/0x1C).
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct ResponseHeader {
    /// BE u16 @0x04 — bytes following the 32-byte header. For a control
    /// completion this spans the echoed SETUP (8 bytes) plus the transfer DATA.
    pub payload_len: u16,
    /// Byte @0x06 — status sub-byte (the ack status for the 0x0B/0x1D/0x1F group).
    pub status: u8,
    /// Byte @0x07 — opcode / dispatch key.
    pub opcode: u8,
    /// LE u16 @0x08 — SeqNum (echoes the request).
    pub seq: u16,
    /// Byte @0x0A — flags; bit 0x80 selects the completion handler.
    pub flags: u8,
    /// Byte @0x0C — echoed request command (`0x33` ctrl-IN / `0x25` / `0x2D`).
    pub command: u8,
    /// Byte @0x10 — device / USB-port index.
    pub device_index: u8,
    /// BE u16 @0x12 — handle, or (for 0x0A/0x1C) the session frame size.
    pub value: u16,
}

impl ResponseHeader {
    /// Parse a 32-byte header. `buf` must be at least [`HEADER_LEN`] bytes and
    /// begin with the [`MAGIC`] `"UNT$"` signature.
    pub fn parse(buf: &[u8]) -> Result<ResponseHeader, TransportError> {
        if buf.len() < HEADER_LEN {
            return Err(TransportError::Protocol(format!(
                "response header too short: {} < {}",
                buf.len(),
                HEADER_LEN
            )));
        }
        if buf[0x00..0x04] != MAGIC {
            return Err(TransportError::Protocol(format!(
                "bad response magic: expected \"UNT$\", got {:02x?}",
                &buf[0x00..0x04]
            )));
        }
        Ok(ResponseHeader {
            payload_len: u16::from_be_bytes([buf[0x04], buf[0x05]]),
            status: buf[0x06],
            opcode: buf[0x07],
            seq: u16::from_le_bytes([buf[0x08], buf[0x09]]),
            flags: buf[0x0A],
            command: buf[0x0C],
            device_index: buf[0x10],
            value: u16::from_be_bytes([buf[0x12], buf[0x13]]),
        })
    }

    /// Opcode classification for this header.
    pub fn class(&self) -> OpcodeClass {
        classify_opcode(self.opcode)
    }

    /// Whether the completion-handler-select flag (bit 0x80) is set.
    pub fn completion_flag(&self) -> bool {
        self.flags & 0x80 != 0
    }
}

/// A fully-read response frame: header plus the `payload_len` bytes that follow
/// it. For a control data-completion those bytes are the echoed 8-byte SETUP
/// packet followed by the USB transfer DATA (see [`Frame::data`]).
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Frame {
    pub header: ResponseHeader,
    pub payload: Vec<u8>,
}

impl Frame {
    /// The USB **control** transfer DATA stage: `payload` past the 8-byte echoed
    /// SETUP packet, i.e. starting at response offset [`DATA_OFFSET`] (0x28).
    /// Empty if the frame carries only the setup echo (no data stage).
    pub fn data(&self) -> &[u8] {
        self.data_at(SETUP_ECHO_LEN)
    }

    /// The transfer DATA stage at an arbitrary offset *within [`Self::payload`]*
    /// — i.e. measured from the end of the 32-byte header. Use
    /// `SETUP_ECHO_LEN` (8) for a control completion (data at frame 0x28) and
    /// `0` for a bulk completion (data at frame 0x20); see [`TransferKind`].
    /// Returns an empty slice if the payload is shorter than `offset`.
    pub fn data_at(&self, offset: usize) -> &[u8] {
        self.payload.get(offset..).unwrap_or(&[])
    }

    /// The transfer DATA stage selected by [`TransferKind`].
    pub fn data_for(&self, kind: TransferKind) -> &[u8] {
        self.data_at(kind.payload_data_offset())
    }
}

/// Read one response frame from `r`: the fixed 32-byte header, then exactly
/// `payload_len` payload bytes. Both stages loop (`read_exact`) so frames of any
/// size — including larger than [`MAX_RX_FRAME`] — are reassembled.
///
/// Returns [`TransportError::Closed`] if the stream ends at a frame boundary or
/// mid-frame.
pub async fn read_frame<R>(r: &mut R) -> Result<Frame, TransportError>
where
    R: AsyncRead + Unpin,
{
    let (frame, _raw) = read_frame_raw(r).await?;
    Ok(frame)
}

/// As [`read_frame`], but also return the frame's **raw on-wire bytes** (the
/// 32-byte header followed by the payload). Used by the request path to hexdump
/// exactly what arrived (see [`debug_hexdump`]) so the bulk-IN data offset can
/// be confirmed against a live capture.
pub async fn read_frame_raw<R>(r: &mut R) -> Result<(Frame, Vec<u8>), TransportError>
where
    R: AsyncRead + Unpin,
{
    let mut header_buf = [0u8; HEADER_LEN];
    read_exact_or_closed(r, &mut header_buf).await?;
    let header = ResponseHeader::parse(&header_buf)?;

    let mut payload = vec![0u8; header.payload_len as usize];
    read_exact_or_closed(r, &mut payload).await?;

    let mut raw = Vec::with_capacity(HEADER_LEN + payload.len());
    raw.extend_from_slice(&header_buf);
    raw.extend_from_slice(&payload);

    Ok((Frame { header, payload }, raw))
}

/// Environment flag enabling verbose wire logging (`ITEC_DEBUG` set to anything).
pub const DEBUG_ENV: &str = "ITEC_DEBUG";

/// Whether [`DEBUG_ENV`] (`ITEC_DEBUG`) is set in the environment.
fn debug_enabled() -> bool {
    std::env::var_os(DEBUG_ENV).is_some()
}

/// Log a single open-sequence step to stderr when `ITEC_DEBUG` is set.
fn debug_step(msg: &str) {
    if debug_enabled() {
        eprintln!("[ITEC_DEBUG] {msg}");
    }
}

/// Hexdump the first `~48` bytes of a raw frame to stderr when `ITEC_DEBUG` is
/// set. `dir` is a short label such as `"TX"` or `"RX"`.
fn debug_hexdump(dir: &str, buf: &[u8]) {
    if !debug_enabled() {
        return;
    }
    const MAX: usize = 48;
    let n = buf.len().min(MAX);
    let hex: String = buf[..n]
        .iter()
        .map(|b| format!("{b:02x}"))
        .collect::<Vec<_>>()
        .join(" ");
    let more = if buf.len() > MAX { " ..." } else { "" };
    eprintln!("[ITEC_DEBUG] {dir} {} bytes: {hex}{more}", buf.len());
}

/// `read_exact` that maps a clean EOF to [`TransportError::Closed`].
async fn read_exact_or_closed<R>(r: &mut R, buf: &mut [u8]) -> Result<(), TransportError>
where
    R: AsyncRead + Unpin,
{
    if buf.is_empty() {
        return Ok(());
    }
    match r.read_exact(buf).await {
        Ok(_) => Ok(()),
        Err(e) if e.kind() == std::io::ErrorKind::UnexpectedEof => Err(TransportError::Closed),
        Err(e) => Err(TransportError::Io(e)),
    }
}

/// The result of routing one [`Frame`] through the [`Dispatcher`].
#[derive(Debug, Clone, PartialEq, Eq)]
pub enum Dispatch {
    /// Data completion for `seq`; `payload` is the **raw** frame payload (all
    /// bytes past the 32-byte header). The caller strips the leading echoed
    /// SETUP for a control transfer, or nothing for a bulk transfer — see
    /// [`TransferKind`] / [`Frame::data_for`]. (The dispatcher cannot tell the
    /// two apart: both use the same data-completion opcodes.)
    Completion { seq: u16, payload: Vec<u8> },
    /// Control/ack for `seq` carrying `status` (header byte @0x06).
    Ack { seq: u16, status: u8 },
    /// Session/frame-size ack; `size` has been latched into the dispatcher.
    SessionSize { size: u16 },
    /// Opcode not recognized; left for the caller to log/ignore.
    Unknown { opcode: u8 },
}

/// Routes parsed response frames by opcode group (notes §2) and latches the
/// negotiated session frame size from `0x0A`/`0x1C` acks.
///
/// This is the decoded half of the per-port Rx thread (`GetDataFromTDI`): it has
/// no socket of its own, so it is driven by [`read_frame`] and is unit-testable
/// in isolation.
#[derive(Debug, Default)]
pub struct Dispatcher {
    session_frame_size: Option<u16>,
}

impl Dispatcher {
    pub fn new() -> Self {
        Dispatcher::default()
    }

    /// The session send-frame size latched from a `0x0A`/`0x1C` ack, if seen.
    pub fn session_frame_size(&self) -> Option<u16> {
        self.session_frame_size
    }

    /// Route one frame, latching the session size as a side effect for the
    /// `SessionSize` group.
    pub fn dispatch(&mut self, frame: Frame) -> Dispatch {
        match frame.header.class() {
            // Hand back the raw payload; the request path slices off the echoed
            // SETUP (control, resp 0x28) or nothing (bulk, resp 0x20) by kind.
            OpcodeClass::Data => Dispatch::Completion {
                seq: frame.header.seq,
                payload: frame.payload,
            },
            OpcodeClass::Ack => Dispatch::Ack {
                seq: frame.header.seq,
                status: frame.header.status,
            },
            OpcodeClass::SessionSize => {
                self.session_frame_size = Some(frame.header.value);
                Dispatch::SessionSize {
                    size: frame.header.value,
                }
            }
            OpcodeClass::Unknown => Dispatch::Unknown {
                opcode: frame.header.opcode,
            },
        }
    }
}

/// 16-bit request SeqNum allocator (notes §3): monotonic counter, `lock xadd`
/// per request, **skipping the value 0**.
#[derive(Debug)]
pub struct SeqAllocator {
    next: AtomicU16,
}

impl Default for SeqAllocator {
    fn default() -> Self {
        SeqAllocator::new()
    }
}

impl SeqAllocator {
    /// A fresh allocator whose first handed-out SeqNum is 1.
    pub fn new() -> Self {
        SeqAllocator {
            next: AtomicU16::new(1),
        }
    }

    /// An allocator primed to hand out `start` next (useful for testing the
    /// wrap-around skip of 0).
    pub fn starting_at(start: u16) -> Self {
        SeqAllocator {
            next: AtomicU16::new(start),
        }
    }

    /// Allocate the next SeqNum, skipping 0 on wrap (atomic, thread-safe).
    pub fn next_seq(&self) -> u16 {
        loop {
            let v = self.next.fetch_add(1, Ordering::Relaxed);
            if v != 0 {
                return v;
            }
            // `v == 0` means the counter just wrapped through 0; skip it and let
            // the next fetch_add return 1.
        }
    }
}

// --- Request (TX) wire format — THE SEAM --------------------------------------
//
// These two functions are the ONLY pieces left to implement. The exact TX bytes
// (the `"UNT$"` descriptor, command code @0x1C, and how `0x3d284` serializes it
// on the wire) are being finalized by another worker; see notes §3 "Request (TX)
// wire format" and §8. Do NOT guess the layout here. Everything else in this
// module (RX parsing, dispatch, SeqNum, request/response plumbing below) is
// already wired to call these, so filling them in completes the transport.

/// The 16-byte descending-counter placeholder template emitted at descriptor
/// offset 0x00–0x0F (notes §9.0; `.rdata@0x25c80`). The server is understood to
/// ignore these bytes, but the client always emits them verbatim.
const PLACEHOLDER_TEMPLATE: [u8; 16] = [
    0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01,
];

// --- Configuration selection / pipe-open (GenHC FUN_00016d08 + FUN_0001c104) --
//
// Before any bulk transfer the driver performs URB_FUNCTION_SELECT_CONFIGURATION:
//   * `FUN_00016d08` parses the device's CONFIGURATION descriptor
//     (`USBD_ParseConfigurationDescriptorEx` / `USBD_ParseDescriptors(..,5)`),
//     looping over every endpoint and allocating a per-pipe struct via
//     `FUN_0001c104` (pool tag "Est2", 0xa8 bytes);
//   * `FUN_00016c48` then issues the standard **SET_CONFIGURATION** request
//     (bRequest 0x09) as an ordinary §9.1 control transfer.
//
// The per-pipe **handle** lives at pipe-struct byte +0x48 (`*(plVar5 + 9)` in
// `FUN_0001c104`). The bulk serializer `FUN_0001b110` copies it to on-wire byte
// **0x20** (`*(param_4 + 4) = *(*(urb+0x18) + 0x48)`) and writes the two
// constants **0x22 = 0x30** and **0x23 = 0xF0**. Our old `build_bulk_request`
// left 0x20/0x22/0x23 at zero, so the server never matched the pipe. [C]

/// Constant written at bulk-request byte 0x22 by the pipe serializer
/// (`FUN_0001b110`: `*(param_4 + 0x22) = 0x30`). [C]
pub const BULK_BYTE_0X22: u8 = 0x30;

/// Constant written at bulk-request byte 0x23 by the pipe serializer
/// (`FUN_0001b110`: `*(param_4 + 0x23) = 0xF0`). [C]
pub const BULK_BYTE_0X23: u8 = 0xF0;

/// Per-pipe handle (pipe-struct +0x48 → bulk byte 0x20) for control transfers
/// and for a bulk-OUT pipe on a vendor-class device: `0x01` (`FUN_0001c104`
/// default; control uses a literal `0x20 = 0x01`). [C]
pub const PIPE_HANDLE_DEFAULT: u8 = 0x01;

/// Per-pipe handle for a bulk-IN pipe on a vendor-class device such as the
/// PL2303: `0x81` (`FUN_0001c104`). [C/I — see [`pipe_handle`]]
pub const PIPE_HANDLE_BULK_IN: u8 = 0x81;

/// USB endpoint transfer type (bmAttributes & 0x3) for a bulk endpoint.
const EP_ATTR_BULK: u8 = 2;

/// Compute the per-pipe handle (pipe-struct byte +0x48, emitted at bulk byte
/// 0x20) exactly as GenHC `FUN_0001c104` does from the endpoint + interface
/// descriptors:
///   * non-bulk pipe (control / interrupt / isochronous) → `0x01`;
///   * **bulk-OUT** → `0x81` only for interface class 7 (printer), else `0x01`;
///   * **bulk-IN** → `0x01` for mass-storage (interface class 8), else `0x81`.
///
/// The decompiled bulk-IN branch also returns `0x01` for two device-speed
/// markers (`*(devExt+0x7c)` ∈ {0x4b8, 0x4e8}) that cannot be read offline; the
/// full-speed vendor-class PL2303 matches none of them, so a PL2303 bulk-IN pipe
/// resolves to **0x81** and bulk-OUT to **0x01**. [C for the class branches;
/// the speed exception is LIVE-UNCONFIRMED but does not apply to the PL2303.]
pub fn pipe_handle(ep_addr: u8, attributes: u8, iface_class: u8) -> u8 {
    if attributes & 0x3 != EP_ATTR_BULK {
        return PIPE_HANDLE_DEFAULT;
    }
    let dir_in = ep_addr & 0x80 != 0;
    if dir_in {
        // bulk-IN
        if iface_class == 8 {
            PIPE_HANDLE_DEFAULT
        } else {
            PIPE_HANDLE_BULK_IN
        }
    } else {
        // bulk-OUT
        if iface_class == 7 {
            0x81
        } else {
            PIPE_HANDLE_DEFAULT
        }
    }
}

/// The bulk-endpoint pipe handles resolved for a configuration: the value to
/// place at bulk byte 0x20 for the OUT (serial TX, EP2) and IN (serial RX, EP3)
/// pipes. Defaults match a PL2303 before the config descriptor has been read.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct BulkHandles {
    /// Handle for the bulk-OUT pipe (EP2).
    pub out: u8,
    /// Handle for the bulk-IN pipe (EP3).
    pub in_: u8,
}

impl Default for BulkHandles {
    fn default() -> Self {
        BulkHandles {
            out: PIPE_HANDLE_DEFAULT,
            in_: PIPE_HANDLE_BULK_IN,
        }
    }
}

/// A USB CONFIGURATION descriptor parsed just enough to drive SELECT_CONFIGURATION
/// and compute the bulk pipe handles.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct ConfigDescriptor {
    /// `bConfigurationValue` (CONFIGURATION descriptor +5) — the argument of the
    /// SET_CONFIGURATION request.
    pub config_value: u8,
    /// `bInterfaceClass` of the (first) interface — drives the handle rules.
    pub iface_class: u8,
    /// Resolved bulk pipe handles for byte 0x20.
    pub handles: BulkHandles,
}

/// Parse a USB CONFIGURATION descriptor blob (the standard TLV walk: each
/// descriptor is `[bLength, bDescriptorType, ..]`), extracting
/// `bConfigurationValue`, the interface class, and the bulk pipe handles.
///
/// Mirrors GenHC `FUN_00016d08`: walk INTERFACE (type 0x04) and ENDPOINT (type
/// 0x05) descriptors, and for each bulk endpoint compute [`pipe_handle`] against
/// the most recent interface's class.
pub fn parse_config_descriptor(buf: &[u8]) -> Result<ConfigDescriptor, TransportError> {
    if buf.len() < 9 || buf[1] != 0x02 {
        let dtype = buf.get(1).copied().unwrap_or(0);
        return Err(TransportError::Protocol(format!(
            "not a CONFIGURATION descriptor (len {}, type {dtype:#04x})",
            buf.len()
        )));
    }
    let config_value = buf[5];
    let mut iface_class = 0xFF; // vendor-specific until an INTERFACE says otherwise
    let mut handles = BulkHandles::default();
    let mut saw_bulk_out = false;
    let mut saw_bulk_in = false;

    let mut i = 0usize;
    while i + 2 <= buf.len() {
        let len = buf[i] as usize;
        if len < 2 || i + len > buf.len() {
            break;
        }
        match buf[i + 1] {
            0x04 if len >= 6 => iface_class = buf[i + 5], // INTERFACE: bInterfaceClass @ +5
            0x05 if len >= 4 => {
                // ENDPOINT: bEndpointAddress @ +2, bmAttributes @ +3.
                let addr = buf[i + 2];
                let attr = buf[i + 3];
                if attr & 0x3 == EP_ATTR_BULK {
                    let h = pipe_handle(addr, attr, iface_class);
                    if addr & 0x80 != 0 {
                        handles.in_ = h;
                        saw_bulk_in = true;
                    } else {
                        handles.out = h;
                        saw_bulk_out = true;
                    }
                }
            }
            _ => {}
        }
        i += len;
    }

    if !saw_bulk_out || !saw_bulk_in {
        debug_step(&format!(
            "config descriptor parsed but missing a bulk pipe (out={saw_bulk_out}, in={saw_bulk_in}); \
             using defaults for the missing direction"
        ));
    }
    Ok(ConfigDescriptor {
        config_value,
        iface_class,
        handles,
    })
}

/// Build the on-wire bytes for a USB **control** transfer request.
///
/// Implements the descriptor-is-the-wire layout from notes §9.1 (the MDL covers
/// the descriptor from offset 0; there is no separate header and no reordering).
/// The returned buffer runs from 0x00 through the end of the data stage; the
/// send path zero-pads it out to the negotiated session frame size.
///
/// * `seq` — SeqNum from [`SeqAllocator::next_seq`] (echoed back at header+0x08).
/// * `setup` — the 8-byte USB SETUP packet (bmRequestType, bRequest, wValue,
///   wIndex, wLength), as produced by [`encode_setup_packet`].
/// * `data` — the control OUT data stage, or `None` for an IN / no-data request.
/// * `dir_in` — `true` for a device→host (control-IN) transfer.
/// * `device_index` — USB-port / device index (descriptor 0x16; notes §9.1).
pub fn build_control_request(
    seq: u16,
    setup: &[u8; 8],
    data: Option<&[u8]>,
    dir_in: bool,
    device_index: u8,
) -> Result<Vec<u8>, TransportError> {
    // Treat an empty OUT stage the same as no data stage.
    let out_data = data.filter(|d| !d.is_empty());

    // wLength is the little-endian u16 at setup[6..8].
    let wlength = u16::from_le_bytes([setup[6], setup[7]]);

    // "Following length" (12-bit): 8 for a control-IN (setup only), wLength+8
    // for a control-OUT that carries a data stage (notes §9.1).
    let following_len: u16 = if !dir_in && out_data.is_some() {
        wlength.wrapping_add(8)
    } else {
        8
    };

    // Command code @0x1C (notes §9.1 / §6).
    let command: u8 = if dir_in {
        0x33 // control-IN
    } else if out_data.is_some() {
        0x2D // control-OUT with data
    } else {
        0x25 // control-OUT, no data
    };

    let data_len = out_data.map_or(0, <[u8]>::len);
    let mut buf = vec![0u8; 0x38 + data_len];

    buf[0x00..0x10].copy_from_slice(&PLACEHOLDER_TEMPLATE);
    buf[0x10..0x14].copy_from_slice(b"UNT$");
    // 0x14 = high nibble of the 12-bit length, 0x15 = low byte.
    buf[0x14] = ((following_len >> 8) & 0x0F) as u8;
    buf[0x15] = (following_len & 0xFF) as u8;
    buf[0x16] = device_index;
    buf[0x17] = 0x00; // transfer-type: control
    let seq_le = seq.to_le_bytes();
    buf[0x18] = seq_le[0];
    buf[0x19] = seq_le[1];
    buf[0x1C] = command;
    buf[0x20] = 0x01; // constant
    buf[0x21] = setup[2]; // wValue low
    buf[0x22] = setup[3]; // wValue high
    buf[0x23] = setup[4]; // wIndex low
    // 0x24/0x25 mirror the length byte-swapped: 0x24 = low byte, 0x25 = high nibble.
    buf[0x24] = (following_len & 0xFF) as u8;
    buf[0x25] = ((following_len >> 8) & 0x0F) as u8;
    buf[0x26] = setup[6]; // wLength low
    buf[0x27] = setup[7]; // wLength high
    buf[0x28] = setup[0]; // bmRequestType
    buf[0x29] = setup[1]; // bRequest
    buf[0x2A] = setup[5] & 0x7F; // wIndex high (bit7 forced 0)
    // 0x2D/0x2E/0x2F: endpoint/addr nibbles + direction flag. For EP0 control the
    // confirmed layout is 0x2D=0x00, 0x2E=deviceIndex&0xf, 0x2F=0x08 (notes §9.1).
    buf[0x2D] = 0x00;
    buf[0x2E] = device_index & 0x0F;
    buf[0x2F] = 0x08;
    // The 8-byte USB SETUP packet, duplicated verbatim at 0x30.
    buf[0x30..0x38].copy_from_slice(setup);
    // OUT data payload (command 0x2D only).
    if let Some(d) = out_data {
        buf[0x38..].copy_from_slice(d);
    }

    Ok(buf)
}

/// Build the on-wire bytes for a USB **bulk / interrupt** transfer request.
///
/// * `seq` — SeqNum from [`SeqAllocator::next_seq`].
/// * `data` — the OUT payload for this frame, or `None` for an IN request.
/// * `offset` — 32-bit segment offset for segmented transfers (notes §3).
/// * `request_len` — bytes requested for an IN transfer (ignored for OUT).
/// * `dir_in` — `true` for a device→host (bulk-IN) transfer.
/// * `device_index` — USB-port / device index (descriptor 0x16; notes §9.3).
/// * `pipe_handle` — the per-pipe handle (pipe-struct +0x48) emitted at byte
///   0x20, from [`pipe_handle`] / the SELECT_CONFIGURATION step. Without it the
///   server does not match the pipe and the device ignores the frame.
///
/// Implements a **single-segment** frame (notes §9.3): segment count @0x1E = 1,
/// current index @0x1F = 0, with the whole payload carried in this one frame.
///
/// TODO(multi-segment): large transfers are split into `0x1E` segments with a
/// host-tracked 32-bit byte offset (`offset`). That path is not implemented yet;
/// a payload that does not fit the 12-bit per-frame length field is rejected.
pub fn build_bulk_request(
    seq: u16,
    data: Option<&[u8]>,
    offset: u32,
    request_len: u32,
    dir_in: bool,
    device_index: u8,
    pipe_handle: u8,
) -> Result<Vec<u8>, TransportError> {
    // `offset` is reserved for the not-yet-implemented segmented path (§9.3),
    // where it names the running byte offset into the URB buffer. For a single
    // segment it is always 0.
    let _ = offset;

    let out_data = data.filter(|d| !d.is_empty());

    // Per-frame payload length (12-bit field @0x14/0x15, mirror @0x24/0x25):
    // the OUT bytes carried here, or the IN bytes requested.
    let frame_len: u32 = if dir_in {
        request_len
    } else {
        out_data.map_or(0, |d| d.len() as u32)
    };
    if frame_len > 0x0FFF {
        return Err(TransportError::Protocol(format!(
            "bulk frame length {frame_len} exceeds the single-frame 12-bit limit \
             (multi-segment TX not implemented)"
        )));
    }
    let frame_len = frame_len as u16;

    // Transfer-type @0x17 (notes §9.3): 0x04 = bulk-IN, 0x02 = bulk-OUT.
    let transfer_type: u8 = if dir_in { 0x04 } else { 0x02 };

    let data_len = out_data.map_or(0, <[u8]>::len);
    let mut buf = vec![0u8; 0x30 + data_len];

    buf[0x00..0x10].copy_from_slice(&PLACEHOLDER_TEMPLATE);
    buf[0x10..0x14].copy_from_slice(b"UNT$");
    buf[0x14] = ((frame_len >> 8) & 0x0F) as u8;
    buf[0x15] = (frame_len & 0xFF) as u8;
    buf[0x16] = device_index;
    buf[0x17] = transfer_type;
    let seq_le = seq.to_le_bytes();
    buf[0x18] = seq_le[0];
    buf[0x19] = seq_le[1];
    buf[0x1C] = 0x00; // command byte unused for bulk; 0x17 carries the type
    buf[0x1E] = 0x01; // total segment count (single segment)
    buf[0x1F] = 0x00; // current segment index
    // Per-pipe handle @0x20 (pipe-struct +0x48) plus the two constants @0x22/0x23
    // written by the pipe serializer FUN_0001b110. These activate the pipe on the
    // server; leaving them zero (the old bug) makes the device ignore the frame.
    buf[0x20] = pipe_handle;
    buf[0x22] = BULK_BYTE_0X22; // 0x30
    buf[0x23] = BULK_BYTE_0X23; // 0xF0
    // 0x24/0x25 mirror the length byte-swapped (as in the control layout).
    buf[0x24] = (frame_len & 0xFF) as u8;
    buf[0x25] = ((frame_len >> 8) & 0x0F) as u8;
    // Pipe fields (notes §10.4; PL2303 standard HX/TA endpoints):
    //   * 0x2C = wMaxPacketSize low byte (0x40).
    //   * 0x2E = endpoint number in the high nibble, deviceIndex in the low.
    //     Bulk-OUT = EP2 (serial TX) -> 0x2?, Bulk-IN = EP3 (serial RX) -> 0x3?.
    //   * 0x2F = dir/type flags: bit 0x04 = IN; bits 4-5 = bulk attr -> 0x20.
    //   * 0x2D = maxpkt-hi + port; 0x00 for EP0/0x40-byte bulk, deviceIndex 1.
    let ep_num: u8 = if dir_in { 3 } else { 2 };
    buf[0x2C] = 0x40;
    buf[0x2D] = 0x00;
    buf[0x2E] = (ep_num << 4) | (device_index & 0x0F);
    buf[0x2F] = if dir_in { 0x24 } else { 0x20 };
    // Bulk data payload starts at 0x30 (no duplicated SETUP block).
    if let Some(d) = out_data {
        buf[0x30..].copy_from_slice(d);
    }

    Ok(buf)
}

/// Pack a [`pl2303::ControlRequest`] into the 8-byte USB SETUP packet.
///
/// Standard USB layout: `bmRequestType, bRequest, wValue(LE), wIndex(LE),
/// wLength(LE)`. `wLength` is the length of the data stage.
pub fn encode_setup_packet(req: &pl2303::ControlRequest) -> [u8; 8] {
    let value = req.value.to_le_bytes();
    let index = req.index.to_le_bytes();
    let wlen = (req.data.len() as u16).to_le_bytes();
    [
        req.request_type,
        req.request,
        value[0],
        value[1],
        index[0],
        index[1],
        wlen[0],
        wlen[1],
    ]
}

// --- Session claim / keep-alive (notes §10.1; LIVE-CONFIRMED claim) -----------

/// Fixed on-wire size of the session-claim frame: 116 bytes (0x74). The claim is
/// sent at **exactly** this length — it is the one frame that is NOT padded out
/// to the session frame size (LIVE-CONFIRMED).
pub const CLAIM_LEN: usize = 0x74;

/// Claim frame type byte @0x17 — the 0x0A session-open / claim message.
pub const CLAIM_TYPE: u8 = 0x0A;

/// Keep-alive frame type byte @0x17.
pub const KEEPALIVE_TYPE: u8 = 0x12;

/// Opcode (response header @0x07) of the server's claim acknowledgement
/// (LIVE-CONFIRMED: `55 4e 54 24 ... 0b ...`).
pub const OPCODE_CLAIM_ACK: u8 = 0x0B;

/// Default / fallback session frame size (0x5B4 = 1460), latched when the claim
/// ack carries no size (notes §10.2; the live ack reports BE `05 b4` @0x12).
pub const DEFAULT_SESSION_FRAME_SIZE: u16 = 0x5B4;

// LIVE-UNCONFIRMED: keepalive interval/exact bytes.
/// Keep-alive period. The notes seed a `0x3c` (=60) value at
/// `ctx+index*0x268+0x1024` but the unit (s / ds) is unknown; default to 5s and
/// tune against the live device.
pub const KEEPALIVE_INTERVAL: Duration = Duration::from_secs(5);

/// Build the 116-byte session-**claim** frame (notes §10.1; LIVE-CONFIRMED).
///
/// Layout (all other bytes zero): the 16-byte placeholder @0x00, `"UNT$"` @0x10,
/// the `0x4400` following-length field as a LE u16 @0x14, the device/port index
/// @0x16 **and** @0x20, the claim type `0x0A` @0x17, SeqNum (LE) @0x18 and flag
/// `0x80` @0x1A. Sent at exactly [`CLAIM_LEN`] — never padded to the frame size.
pub fn build_claim(seq: u16, device_index: u8) -> Vec<u8> {
    let mut buf = vec![0u8; CLAIM_LEN];
    buf[0x00..0x10].copy_from_slice(&PLACEHOLDER_TEMPLATE);
    buf[0x10..0x14].copy_from_slice(b"UNT$");
    // The 0x4400 "following-length" field, little-endian u16 (=> 0x14=0x00,
    // 0x15=0x44).
    buf[0x14..0x16].copy_from_slice(&0x4400u16.to_le_bytes());
    buf[0x16] = device_index;
    buf[0x17] = CLAIM_TYPE;
    buf[0x18..0x1A].copy_from_slice(&seq.to_le_bytes());
    buf[0x1A] = 0x80;
    buf[0x20] = device_index;
    buf
}

/// Build a periodic **keep-alive** frame (notes §10.1), padded to `frame_size`.
///
/// Same placeholder + `"UNT$"` header shape as the claim: device/port index
/// @0x16 and @0x20, type `0x12` @0x17, a fresh SeqNum (LE) @0x18 and flag `0x80`
/// @0x1A.
///
// LIVE-UNCONFIRMED: keepalive interval/exact bytes.
pub fn build_keepalive(seq: u16, device_index: u8, frame_size: u16) -> Vec<u8> {
    // Guard against a pathological frame size that could not even hold the
    // header (the real negotiated value is 1460).
    let len = (frame_size as usize).max(0x30);
    let mut buf = vec![0u8; len];
    buf[0x00..0x10].copy_from_slice(&PLACEHOLDER_TEMPLATE);
    buf[0x10..0x14].copy_from_slice(b"UNT$");
    buf[0x16] = device_index;
    buf[0x17] = KEEPALIVE_TYPE;
    buf[0x18..0x1A].copy_from_slice(&seq.to_le_bytes());
    buf[0x1A] = 0x80;
    buf[0x20] = device_index;
    buf
}

/// Resolve the session frame size from a claim-ack header: the BE u16 @0x12, or
/// [`DEFAULT_SESSION_FRAME_SIZE`] when the ack carries none.
fn session_size_from_ack(header: &ResponseHeader) -> u16 {
    if header.value != 0 {
        header.value
    } else {
        DEFAULT_SESSION_FRAME_SIZE
    }
}

/// Spawn the background keep-alive task. It shares the connection's write half
/// (behind an async mutex) and SeqNum allocator, waking on [`KEEPALIVE_INTERVAL`]
/// to emit a `0x12` frame until a write fails (e.g. the socket closed).
// LIVE-UNCONFIRMED: keepalive interval/exact bytes.
fn spawn_keepalive(
    writer: Arc<Mutex<OwnedWriteHalf>>,
    seq: Arc<SeqAllocator>,
    device_index: u8,
    frame_size: u16,
) -> JoinHandle<()> {
    tokio::spawn(async move {
        let mut tick = tokio::time::interval(KEEPALIVE_INTERVAL);
        tick.tick().await; // consume the immediate first tick
        loop {
            tick.tick().await;
            let frame = build_keepalive(seq.next_seq(), device_index, frame_size);
            let mut w = writer.lock().await;
            if w.write_all(&frame).await.is_err() || w.flush().await.is_err() {
                break;
            }
        }
    })
}

/// The real transport. Holds the (split) TCP connection to the ESTI box, the
/// SeqNum allocator, the response dispatcher, the negotiated session frame size
/// and the background keep-alive task.
pub struct Esti4660Transport {
    /// Read half, drained by [`read_frame`] inside [`Esti4660Transport::request`].
    reader: OwnedReadHalf,
    /// Write half, shared with the keep-alive task behind an async mutex.
    writer: Arc<Mutex<OwnedWriteHalf>>,
    peer: SocketAddr,
    seq: Arc<SeqAllocator>,
    dispatcher: Dispatcher,
    /// USB-port / device index written into every request descriptor (0x16).
    /// One connection serves one claimed port; defaults to the first device.
    device_index: u8,
    /// Negotiated send-frame size (latched from the claim ack, default 1460).
    /// Every request frame is zero-padded to this before being sent.
    session_frame_size: u16,
    /// Bulk pipe handles (byte 0x20) resolved by [`Self::select_configuration`]
    /// from the device's configuration descriptor; PL2303 defaults until then.
    bulk_handles: BulkHandles,
    /// Handle to the background keep-alive task, aborted on drop.
    keepalive: Option<JoinHandle<()>>,
}

impl Drop for Esti4660Transport {
    fn drop(&mut self) {
        if let Some(h) = self.keepalive.take() {
            h.abort();
        }
    }
}

/// The default USB-port / device index for a freshly-connected transport
/// (notes §9.2 confirmed example uses index 1).
pub const DEFAULT_DEVICE_INDEX: u8 = 1;

impl Esti4660Transport {
    /// Open a TCP connection to the ESTI box and perform the session claim.
    ///
    /// Steps (notes §10.1; LIVE-CONFIRMED claim): TCP-connect, send the 116-byte
    /// `0x0A` claim frame (at exactly [`CLAIM_LEN`], never padded), read the
    /// server's `0x0B` claim ack and latch the session frame size (BE @0x12), then
    /// spawn the background keep-alive task. The claim is REQUIRED — without it
    /// the server tears the connection down after a single transfer.
    pub async fn connect(addr: SocketAddr) -> Result<Self, TransportError> {
        let stream = TcpStream::connect(addr).await?;
        let (mut reader, writer) = stream.into_split();
        let writer = Arc::new(Mutex::new(writer));
        let seq = Arc::new(SeqAllocator::new());
        let device_index = DEFAULT_DEVICE_INDEX;

        // Session claim: sent at exactly 116 bytes (NOT padded to the frame size).
        let claim = build_claim(seq.next_seq(), device_index);
        {
            let mut w = writer.lock().await;
            w.write_all(&claim).await?;
            w.flush().await?;
        }

        // Await the server's claim ack (opcode 0x0B) and latch the frame size.
        let ack = read_frame(&mut reader).await?;
        if ack.header.opcode != OPCODE_CLAIM_ACK {
            return Err(TransportError::Protocol(format!(
                "expected claim ack opcode {OPCODE_CLAIM_ACK:#04x}, got {:#04x}",
                ack.header.opcode
            )));
        }
        let session_frame_size = session_size_from_ack(&ack.header);

        let keepalive = spawn_keepalive(
            Arc::clone(&writer),
            Arc::clone(&seq),
            device_index,
            session_frame_size,
        );

        let mut transport = Esti4660Transport {
            reader,
            writer,
            peer: addr,
            seq,
            dispatcher: Dispatcher::new(),
            device_index,
            session_frame_size,
            bulk_handles: BulkHandles::default(),
            keepalive: Some(keepalive),
        };

        // Configuration selection / pipe-open (GenHC FUN_00016d08 + FUN_0001c104):
        // GET the configuration descriptor, compute the bulk pipe handles, and
        // issue SET_CONFIGURATION to activate EP2/EP3. Without this the server
        // never opens the bulk pipes and bulk-IN always returns 0 — the exact bug
        // this fixes. Tolerant: on failure keep the PL2303 default handles so the
        // open still proceeds (clearly logged for the live run).
        match transport.select_configuration().await {
            Ok(cfg) => {
                transport.bulk_handles = cfg.handles;
                debug_step(&format!(
                    "select_configuration: cfg={} iface_class={:#04x} handles out={:#04x} in={:#04x}",
                    cfg.config_value, cfg.iface_class, cfg.handles.out, cfg.handles.in_
                ));
            }
            Err(e) => debug_step(&format!(
                "select_configuration failed ({e}); using default bulk handles out={:#04x} in={:#04x}",
                transport.bulk_handles.out, transport.bulk_handles.in_
            )),
        }

        // The Windows Prolific driver runs a vendor init + asserts DTR/RTS when a
        // port is opened; without it the PL2303 won't pass serial data. Do it now
        // so a freshly-connected transport is a usable, opened port (notes §5,
        // §10.1). Defaults to 9600 8N1 — callers re-issue `set_line_coding` to
        // change it.
        transport.open_pl2303(LineCoding::default()).await?;

        Ok(transport)
    }

    /// The remote address this transport is connected to.
    pub fn peer(&self) -> SocketAddr {
        self.peer
    }

    /// The negotiated session send-frame size (latched from the claim ack, or a
    /// later `0x0A`/`0x1C` ack; default [`DEFAULT_SESSION_FRAME_SIZE`]).
    pub fn session_frame_size(&self) -> u16 {
        self.session_frame_size
    }

    /// Zero-pad a request frame out to the negotiated session frame size. Never
    /// truncates (a frame already at/over the size is left as-is).
    fn pad_to_frame_size(&self, frame: &mut Vec<u8>) {
        let target = self.session_frame_size as usize;
        if frame.len() < target {
            frame.resize(target, 0);
        }
    }

    /// Send a pre-built request frame and drive the Rx dispatcher until the
    /// completion (or ack) matching `want_seq` arrives. Session-size acks and
    /// frames for other SeqNums are routed/latched and otherwise skipped.
    ///
    /// Real send/receive plumbing: it is only ever reached once the `build_*`
    /// seam yields actual bytes.
    async fn request(
        &mut self,
        want_seq: u16,
        mut frame: Vec<u8>,
        kind: TransferKind,
    ) -> Result<Vec<u8>, TransportError> {
        self.pad_to_frame_size(&mut frame);
        debug_hexdump("TX", &frame);
        {
            let mut w = self.writer.lock().await;
            w.write_all(&frame).await?;
            w.flush().await?;
        }

        loop {
            let (f, raw) = read_frame_raw(&mut self.reader).await?;
            debug_hexdump("RX", &raw);
            match self.dispatcher.dispatch(f) {
                // `payload` is the raw post-header bytes; strip the echoed SETUP
                // for control (offset 8), nothing for bulk (offset 0).
                Dispatch::Completion { seq, payload } if seq == want_seq => {
                    let off = kind.payload_data_offset();
                    return Ok(payload.get(off..).unwrap_or(&[]).to_vec());
                }
                Dispatch::Ack { seq, status } if seq == want_seq => {
                    return if status == 0 {
                        Ok(Vec::new())
                    } else {
                        Err(TransportError::Protocol(format!(
                            "request seq {want_seq:#06x} failed with status {status:#04x}"
                        )))
                    };
                }
                // A renegotiated session size overwrites the latched value
                // (notes §10.2); frames for other SeqNums are not ours.
                Dispatch::SessionSize { size } => self.session_frame_size = size,
                _ => {}
            }
        }
    }

    /// Issue one PL2303 **control** transfer ([`pl2303::ControlRequest`]) and
    /// await its completion. Direction is taken from `bmRequestType` bit 7
    /// (vendor reads `0xC0` → IN, writes `0x40` / class requests `0x21` → OUT).
    /// The reply is sliced as a control completion (data at resp 0x28).
    async fn send_control(
        &mut self,
        req: &pl2303::ControlRequest,
    ) -> Result<Vec<u8>, TransportError> {
        let setup = encode_setup_packet(req);
        let dir_in = req.request_type & 0x80 != 0;
        let data = if req.data.is_empty() {
            None
        } else {
            Some(req.data.as_slice())
        };
        let seq = self.seq.next_seq();
        let frame = build_control_request(seq, &setup, data, dir_in, self.device_index)?;
        self.request(seq, frame, TransferKind::Control).await
    }

    /// Issue a standard **GET_DESCRIPTOR** control-IN transfer and return the
    /// returned descriptor bytes. `desc_type`/`index` form `wValue`
    /// (`(type << 8) | index`); `len` is the requested `wLength`.
    async fn get_descriptor(
        &mut self,
        desc_type: u8,
        index: u8,
        len: u16,
    ) -> Result<Vec<u8>, TransportError> {
        let req = pl2303::ControlRequest {
            request_type: 0x80, // device-to-host, standard, device
            request: 0x06,      // GET_DESCRIPTOR
            value: (u16::from(desc_type) << 8) | u16::from(index),
            index: 0,
            data: vec![0u8; len as usize],
        };
        self.send_control(&req).await
    }

    /// Perform URB_FUNCTION_SELECT_CONFIGURATION (GenHC `FUN_00016d08` +
    /// `FUN_00016c48`): read the device's CONFIGURATION descriptor, compute the
    /// bulk pipe handles ([`parse_config_descriptor`]), then send the standard
    /// **SET_CONFIGURATION** request (bRequest 0x09) to activate the endpoints.
    ///
    /// Returns the parsed descriptor so the caller can store the handles. Called
    /// from [`Self::connect`] before [`Self::open_pl2303`].
    async fn select_configuration(&mut self) -> Result<ConfigDescriptor, TransportError> {
        // 1. GET_DESCRIPTOR(CONFIGURATION, index 0): first the 9-byte header to
        //    learn wTotalLength (bytes 2..4, LE), then the whole thing.
        debug_step("select_configuration: GET_DESCRIPTOR(config) header");
        let head = self.get_descriptor(0x02, 0, 9).await?;
        debug_hexdump("CFG-HEAD", &head);
        let total = if head.len() >= 4 {
            u16::from_le_bytes([head[2], head[3]]) as usize
        } else {
            head.len()
        };
        let full = if total > head.len() {
            debug_step(&format!("select_configuration: GET_DESCRIPTOR(config) full {total} bytes"));
            let f = self.get_descriptor(0x02, 0, total.min(0x0FFF) as u16).await?;
            debug_hexdump("CFG-FULL", &f);
            f
        } else {
            head
        };

        let cfg = parse_config_descriptor(&full)?;

        // 2. SET_CONFIGURATION(bConfigurationValue): standard host-to-device
        //    control-OUT, no data stage (command 0x25).
        debug_step(&format!(
            "select_configuration: SET_CONFIGURATION value={}",
            cfg.config_value
        ));
        let set_cfg = pl2303::ControlRequest {
            request_type: 0x00, // host-to-device, standard, device
            request: 0x09,      // SET_CONFIGURATION
            value: u16::from(cfg.config_value),
            index: 0,
            data: Vec::new(),
        };
        self.send_control(&set_cfg).await?;
        Ok(cfg)
    }

    /// Perform the full PL2303 port-open initialisation, mirroring what the
    /// Windows Prolific driver does when a port is opened (ordering per the Linux
    /// kernel `drivers/usb/serial/pl2303.c`). Every step is a §9.1 control
    /// transfer via [`Self::send_control`]. In order:
    ///
    /// 1. the classic vendor "magic" reset sequence ([`pl2303::INIT_MAGIC`]:
    ///    vendor reads `0xC0`/`0x01` and writes `0x40`/`0x01`) — **tolerant**: a
    ///    magic step that errors or returns a short read is logged and skipped,
    ///    never aborting the open;
    /// 2. `SET_LINE_CODING` (0x20) for `coding`;
    /// 3. `SET_CONTROL_LINE_STATE` (0x22) asserting **DTR|RTS** (`wValue 0x0003`);
    /// 4. the standard "flow-control off" vendor writes (`wValue 0x0`/`wIndex 0x0`
    ///    and `wValue 0x1`/`wIndex 0x0`).
    ///
    /// Logs each step via `eprintln!` when [`DEBUG_ENV`] (`ITEC_DEBUG`) is set.
    pub async fn open_pl2303(&mut self, coding: LineCoding) -> Result<(), TransportError> {
        debug_step("pl2303 open: begin (vendor magic init)");
        for (i, step) in pl2303::INIT_MAGIC.iter().enumerate() {
            let req = step.to_request();
            debug_step(&format!(
                "pl2303 magic[{i}] type={:#04x} req={:#04x} val={:#06x} idx={:#06x} wlen={}",
                req.request_type,
                req.request,
                req.value,
                req.index,
                req.data.len()
            ));
            // Tolerate short/absent read replies and transient errors: the magic
            // dance is best-effort and must not fail the whole open.
            if let Err(e) = self.send_control(&req).await {
                debug_step(&format!("pl2303 magic[{i}] tolerated error: {e}"));
            }
        }

        debug_step("pl2303 open: SET_LINE_CODING");
        self.send_control(&pl2303::set_line_coding(&coding)).await?;

        debug_step("pl2303 open: SET_CONTROL_LINE_STATE DTR|RTS (wValue=0x0003)");
        self.send_control(&pl2303::set_control_line_state(true, true))
            .await?;

        debug_step("pl2303 open: vendor flow-control-off writes");
        self.send_control(&pl2303::InitStep::Write { value: 0x0, index: 0x0 }.to_request())
            .await?;
        self.send_control(&pl2303::InitStep::Write { value: 0x1, index: 0x0 }.to_request())
            .await?;

        debug_step("pl2303 open: done");
        Ok(())
    }
}

#[async_trait::async_trait]
impl Transport for Esti4660Transport {
    async fn set_line_coding(&mut self, coding: LineCoding) -> Result<(), TransportError> {
        self.send_control(&pl2303::set_line_coding(&coding)).await?;
        Ok(())
    }

    async fn write(&mut self, data: &[u8]) -> Result<usize, TransportError> {
        if data.is_empty() {
            return Ok(0);
        }
        // Usable data per bulk frame = frame_size - 0x30 (notes §10.2).
        let usable = (self.session_frame_size as usize).saturating_sub(0x30).max(1);
        for chunk in data.chunks(usable) {
            let seq = self.seq.next_seq();
            let frame = build_bulk_request(
                seq,
                Some(chunk),
                0,
                0,
                false,
                self.device_index,
                self.bulk_handles.out,
            )?;
            self.request(seq, frame, TransferKind::Bulk).await?;
        }
        Ok(data.len())
    }

    async fn read(&mut self, buf: &mut [u8]) -> Result<usize, TransportError> {
        // Request at most one frame's worth of usable payload, within the 12-bit
        // per-frame length limit.
        let usable = (self.session_frame_size as usize).saturating_sub(0x30).max(1);
        let want = buf.len().min(usable).min(0x0FFF);
        let seq = self.seq.next_seq();
        let frame = build_bulk_request(
            seq,
            None,
            0,
            want as u32,
            true,
            self.device_index,
            self.bulk_handles.in_,
        )?;
        // Bulk-IN reply: data begins at resp 0x20 (no echoed SETUP) — see
        // `BULK_DATA_OFFSET`. LIVE-UNCONFIRMED (0x20 inferred; verify live).
        let payload = self.request(seq, frame, TransferKind::Bulk).await?;
        let n = payload.len().min(buf.len());
        buf[..n].copy_from_slice(&payload[..n]);
        Ok(n)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    /// Ground-truth server reply to GET_DESCRIPTOR(device) seq=1 (58 bytes):
    /// `"UNT$"` @0x00, payload_len `0x001a` @0x04 BE, dispatch opcode `0x01`
    /// @0x07, seq `0x0001` @0x08 LE, echoed command `0x33` @0x0C, echoed SETUP
    /// @0x20..0x27, then the 18-byte device descriptor at 0x28.
    const ORACLE: &[u8] = include_bytes!("../../../raw/getdesc_response.bin");

    /// The 18-byte USB device descriptor carried by [`ORACLE`] at offset 0x28 —
    /// a genuine Prolific PL2303 descriptor (`idVendor 0x067b`, `idProduct
    /// 0x2303`).
    const ORACLE_DATA: [u8; 18] = [
        0x12, 0x01, 0x10, 0x01, 0x00, 0x00, 0x00, 0x40, 0x7b, 0x06, 0x03, 0x23, 0x00, 0x04, 0x01,
        0x02, 0x00, 0x01,
    ];

    /// Build a synthetic 32-byte `"UNT$"` header with the given dispatch opcode,
    /// SeqNum (LE @0x08) and payload length (BE @0x04).
    fn header_bytes(opcode: u8, seq: u16, payload_len: u16) -> [u8; HEADER_LEN] {
        let mut h = [0u8; HEADER_LEN];
        h[0x00..0x04].copy_from_slice(&MAGIC);
        let pl = payload_len.to_be_bytes();
        h[0x04] = pl[0];
        h[0x05] = pl[1];
        h[0x07] = opcode;
        let s = seq.to_le_bytes();
        h[0x08] = s[0];
        h[0x09] = s[1];
        h
    }

    #[test]
    fn parses_oracle_header_fields() {
        let hdr = ResponseHeader::parse(ORACLE).unwrap();
        assert_eq!(hdr.payload_len, 0x1a); // BE @0x04 = 26 = 8 setup + 18 data
        assert_eq!(hdr.opcode, 0x01); // @0x07 => data-completion group
        assert_eq!(hdr.seq, 1); // LE @0x08
        assert_eq!(hdr.command, 0x33); // echoed control-IN command @0x0C
        assert_eq!(hdr.class(), OpcodeClass::Data);
        // Total frame length is HEADER_LEN + payload_len.
        assert_eq!(ORACLE.len(), HEADER_LEN + hdr.payload_len as usize);
    }

    #[test]
    fn bad_magic_is_protocol_error() {
        let mut h = header_bytes(0x01, 1, 0);
        h[0x00] = 0x02; // corrupt the "UNT$" signature
        let err = ResponseHeader::parse(&h).unwrap_err();
        assert!(matches!(err, TransportError::Protocol(_)));
    }

    #[test]
    fn header_too_short_is_protocol_error() {
        let err = ResponseHeader::parse(&[0u8; 8]).unwrap_err();
        assert!(matches!(err, TransportError::Protocol(_)));
    }

    #[test]
    fn opcode_classification_matches_groups() {
        for op in OPCODES_DATA {
            assert_eq!(classify_opcode(op), OpcodeClass::Data);
        }
        for op in OPCODES_ACK {
            assert_eq!(classify_opcode(op), OpcodeClass::Ack);
        }
        for op in OPCODES_SIZE {
            assert_eq!(classify_opcode(op), OpcodeClass::SessionSize);
        }
        assert_eq!(classify_opcode(0x00), OpcodeClass::Unknown);
        assert_eq!(classify_opcode(0xFF), OpcodeClass::Unknown);
    }

    #[tokio::test]
    async fn read_frame_parses_oracle_data() {
        // The whole oracle frame, plus one trailing byte from a following frame.
        let mut bytes = ORACLE.to_vec();
        bytes.push(0x99);

        let mut src: &[u8] = &bytes;
        let frame = read_frame(&mut src).await.unwrap();
        assert_eq!(frame.header.seq, 1);
        assert_eq!(frame.header.command, 0x33);
        // payload is setup echo (8) + data (18); data() strips the setup echo.
        assert_eq!(frame.payload.len(), 0x1a);
        assert_eq!(&frame.payload[..SETUP_ECHO_LEN], &[0x80, 0x06, 0x00, 0x01, 0x00, 0x00, 0x12, 0x00]);
        assert_eq!(frame.data(), &ORACLE_DATA);
        assert_eq!(src, &[0x99]); // one byte of the next frame remains
    }

    #[tokio::test]
    async fn read_frame_loops_for_payload_over_mss() {
        // payload larger than MAX_RX_FRAME (1460) must be reassembled by looping.
        let big = 2000usize;
        let mut h = header_bytes(0x01, 0x1234, big as u16);
        // 2000 does not fit a u16->BE helper cleanly above 0x0FFF nibble concerns,
        // but payload_len is a full 16-bit field, so set it directly.
        h[0x04] = (big >> 8) as u8;
        h[0x05] = (big & 0xff) as u8;
        let mut bytes = h.to_vec();
        bytes.extend(std::iter::repeat(0xAB).take(big));

        let mut src: &[u8] = &bytes;
        let frame = read_frame(&mut src).await.unwrap();
        assert_eq!(frame.payload.len(), big);
        assert!(frame.payload.iter().all(|&b| b == 0xAB));
    }

    #[tokio::test]
    async fn read_frame_eof_is_closed() {
        let mut src: &[u8] = &[];
        assert!(matches!(
            read_frame(&mut src).await,
            Err(TransportError::Closed)
        ));
    }

    #[tokio::test]
    async fn dispatcher_completes_oracle_with_descriptor_data() {
        let mut d = Dispatcher::new();
        let mut src: &[u8] = ORACLE;
        let frame = read_frame(&mut src).await.unwrap();
        let full_payload = frame.payload.clone();
        // The dispatcher now returns the RAW payload (echoed SETUP + DATA); the
        // request path strips the 8-byte SETUP for a control transfer.
        assert_eq!(
            d.dispatch(frame),
            Dispatch::Completion {
                seq: 1,
                payload: full_payload.clone(),
            }
        );
        // Slicing it as a control completion recovers the device descriptor.
        assert_eq!(&full_payload[SETUP_ECHO_LEN..], &ORACLE_DATA);
        assert_eq!(&full_payload[TransferKind::Control.payload_data_offset()..], &ORACLE_DATA);
    }

    #[test]
    fn transfer_kind_data_offsets_match_control_and_bulk() {
        // Control data starts at resp 0x28 (payload +8); bulk at resp 0x20 (+0).
        assert_eq!(TransferKind::Control.payload_data_offset(), SETUP_ECHO_LEN);
        assert_eq!(TransferKind::Control.payload_data_offset(), 8);
        assert_eq!(TransferKind::Bulk.payload_data_offset(), 0);
        assert_eq!(TransferKind::Control.frame_data_offset(), DATA_OFFSET);
        assert_eq!(TransferKind::Control.frame_data_offset(), 0x28);
        assert_eq!(TransferKind::Bulk.frame_data_offset(), BULK_DATA_OFFSET);
        assert_eq!(TransferKind::Bulk.frame_data_offset(), 0x20);
    }

    #[test]
    fn frame_data_at_selects_by_offset() {
        // payload = 8-byte echoed SETUP + 4 data bytes.
        let frame = Frame {
            header: ResponseHeader::parse(&header_bytes(0x01, 1, 12)).unwrap(),
            payload: vec![
                0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, // echoed SETUP
                0x11, 0x22, 0x33, 0x44, // DATA
            ],
        };
        // Control (offset 8) skips the echoed SETUP; bulk (offset 0) keeps all.
        assert_eq!(frame.data(), &[0x11, 0x22, 0x33, 0x44]);
        assert_eq!(frame.data_for(TransferKind::Control), &[0x11, 0x22, 0x33, 0x44]);
        assert_eq!(frame.data_for(TransferKind::Bulk), &frame.payload[..]);
        assert_eq!(frame.data_at(0), &frame.payload[..]);
        // A payload shorter than the offset yields an empty slice, never a panic.
        let short = Frame {
            header: ResponseHeader::parse(&header_bytes(0x01, 1, 2)).unwrap(),
            payload: vec![0x01, 0x02],
        };
        assert!(short.data().is_empty());
    }

    #[test]
    fn vendor_read_setup_packet_encoding() {
        // INIT_MAGIC read: VENDOR_READ (0xC0/0x01), wValue=0x8484, 1-byte IN stage.
        let setup = encode_setup_packet(&pl2303::InitStep::Read { value: 0x8484 }.to_request());
        assert_eq!(setup, [0xC0, 0x01, 0x84, 0x84, 0x00, 0x00, 0x01, 0x00]);
        // It builds a control-IN frame (command 0x33), setup duplicated at 0x30.
        let frame = build_control_request(1, &setup, None, true, 1).unwrap();
        assert_eq!(frame[0x1C], 0x33);
        assert_eq!(&frame[0x30..0x38], &setup);
    }

    #[test]
    fn vendor_write_setup_packet_encoding() {
        // INIT_MAGIC write: VENDOR_WRITE (0x40/0x01), wValue=0x0404, wIndex=1, no data.
        let setup =
            encode_setup_packet(&pl2303::InitStep::Write { value: 0x0404, index: 1 }.to_request());
        assert_eq!(setup, [0x40, 0x01, 0x04, 0x04, 0x01, 0x00, 0x00, 0x00]);
        // No data stage => control-OUT no-data command 0x25.
        let frame = build_control_request(1, &setup, None, false, 1).unwrap();
        assert_eq!(frame[0x1C], 0x25);

        // Flow-control-off writes used by open_pl2303.
        let fc0 = encode_setup_packet(&pl2303::InitStep::Write { value: 0x0, index: 0x0 }.to_request());
        assert_eq!(fc0, [0x40, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
        let fc1 = encode_setup_packet(&pl2303::InitStep::Write { value: 0x1, index: 0x0 }.to_request());
        assert_eq!(fc1, [0x40, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00]);
    }

    #[test]
    fn set_control_line_state_setup_packet_asserts_dtr_rts() {
        // SET_CONTROL_LINE_STATE: type 0x21, req 0x22, wValue=0x0003 (DTR|RTS),
        // wIndex 0, wLength 0.
        let setup = encode_setup_packet(&pl2303::set_control_line_state(true, true));
        assert_eq!(setup, [0x21, 0x22, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00]);
        // Encapsulated as a control-OUT no-data transfer (command 0x25).
        let frame = build_control_request(1, &setup, None, false, 1).unwrap();
        assert_eq!(frame[0x1C], 0x25);
        assert_eq!(frame[0x15], 0x08); // following length = 8
    }

    #[test]
    fn dispatcher_routes_and_latches_session_size() {
        let mut d = Dispatcher::new();
        assert_eq!(d.session_frame_size(), None);

        // ack (0x0B): status byte @0x06, no data stage.
        let mut h = header_bytes(0x0B, 0x1234, 0);
        h[0x06] = 0x00;
        let ack = ResponseHeader::parse(&h).unwrap();
        assert_eq!(
            d.dispatch(Frame {
                header: ack,
                payload: vec![],
            }),
            Dispatch::Ack {
                seq: 0x1234,
                status: 0x00,
            }
        );

        // session size (0x0A): value BE @0x12 = 0x05b4 → latched at ctx+0x2000.
        let mut h = header_bytes(0x0A, 0x1234, 0);
        h[0x12] = 0x05;
        h[0x13] = 0xb4;
        let size = ResponseHeader::parse(&h).unwrap();
        assert_eq!(
            d.dispatch(Frame {
                header: size,
                payload: vec![],
            }),
            Dispatch::SessionSize { size: 0x05b4 }
        );
        assert_eq!(d.session_frame_size(), Some(0x05b4));
    }

    #[test]
    fn seq_allocator_starts_at_one_and_increments() {
        let a = SeqAllocator::new();
        assert_eq!(a.next_seq(), 1);
        assert_eq!(a.next_seq(), 2);
        assert_eq!(a.next_seq(), 3);
    }

    #[test]
    fn seq_allocator_skips_zero_on_wrap() {
        let a = SeqAllocator::starting_at(0xFFFF);
        assert_eq!(a.next_seq(), 0xFFFF);
        // next internal value would be 0 — it must be skipped.
        assert_eq!(a.next_seq(), 1);
        assert_eq!(a.next_seq(), 2);
    }

    /// Ground-truth control-IN frame for GET_DESCRIPTOR(device), notes §9.2.
    #[test]
    fn build_control_request_matches_get_descriptor_oracle() {
        let setup = [0x80, 0x06, 0x00, 0x01, 0x00, 0x00, 0x12, 0x00];
        let frame = build_control_request(1, &setup, None, true, 1).unwrap();

        #[rustfmt::skip]
        let expected: [u8; 0x38] = [
            0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09,
            0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01,
            0x55, 0x4E, 0x54, 0x24, 0x00, 0x08, 0x01, 0x00,
            0x01, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00,
            0x01, 0x00, 0x01, 0x00, 0x08, 0x00, 0x12, 0x00,
            0x80, 0x06, 0x00, 0x00, 0x00, 0x00, 0x01, 0x08,
            0x80, 0x06, 0x00, 0x01, 0x00, 0x00, 0x12, 0x00,
        ];

        // Control-IN with no data stage: the frame is exactly the 0x38-byte base.
        assert_eq!(frame.len(), 0x38);
        assert_eq!(&frame[..], &expected[..]);
    }

    /// Control-OUT with a data stage picks command 0x2D, sets length = wLength+8,
    /// and appends the payload after the duplicated SETUP block at 0x38.
    #[test]
    fn build_control_request_out_with_data() {
        // SET_LINE_CODING: type 0x21 (OUT), req 0x20, wLength 7, 7 data bytes.
        let setup = [0x21, 0x20, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00];
        let payload = [0x80, 0x25, 0x00, 0x00, 0x00, 0x00, 0x08];
        let frame = build_control_request(2, &setup, Some(&payload), false, 1).unwrap();

        assert_eq!(frame.len(), 0x38 + payload.len());
        assert_eq!(frame[0x1C], 0x2D); // control-OUT with data
        // following length = wLength + 8 = 15 = 0x00F
        assert_eq!(frame[0x14], 0x00);
        assert_eq!(frame[0x15], 0x0F);
        assert_eq!(frame[0x24], 0x0F);
        assert_eq!(frame[0x25], 0x00);
        assert_eq!(&frame[0x30..0x38], &setup);
        assert_eq!(&frame[0x38..], &payload);
    }

    /// Control-OUT with no data stage uses command 0x25 and length 8.
    #[test]
    fn build_control_request_out_no_data() {
        let setup = [0x21, 0x22, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00];
        let frame = build_control_request(3, &setup, None, false, 1).unwrap();
        assert_eq!(frame.len(), 0x38);
        assert_eq!(frame[0x1C], 0x25); // control-OUT, no data
        assert_eq!(frame[0x15], 0x08);
    }

    #[test]
    fn build_bulk_request_out_small() {
        let payload = [0xAA, 0xBB, 0xCC, 0xDD];
        let frame = build_bulk_request(0x1234, Some(&payload), 0, 0, false, 1, 0x01).unwrap();

        assert_eq!(frame.len(), 0x30 + payload.len());
        assert_eq!(&frame[0x00..0x10], &PLACEHOLDER_TEMPLATE);
        assert_eq!(&frame[0x10..0x14], b"UNT$");
        assert_eq!(frame[0x14], 0x00); // length hi nibble
        assert_eq!(frame[0x15], 0x04); // length lo byte = 4
        assert_eq!(frame[0x16], 0x01); // device index
        assert_eq!(frame[0x17], 0x02); // bulk-OUT
        assert_eq!(frame[0x18], 0x34); // seq LE lo
        assert_eq!(frame[0x19], 0x12); // seq LE hi => 0x1234
        assert_eq!(frame[0x1C], 0x00); // command unused for bulk
        assert_eq!(frame[0x1E], 0x01); // single segment
        assert_eq!(frame[0x1F], 0x00); // segment index 0
        assert_eq!(frame[0x20], 0x01); // pipe handle (bulk-OUT)
        assert_eq!(frame[0x22], 0x30); // FUN_0001b110 constant
        assert_eq!(frame[0x23], 0xF0); // FUN_0001b110 constant
        assert_eq!(frame[0x24], 0x04); // mirror lo byte
        assert_eq!(frame[0x25], 0x00); // mirror hi nibble
        assert_eq!(&frame[0x30..], &payload);
    }

    #[test]
    fn build_bulk_request_in_small() {
        let frame = build_bulk_request(5, None, 0, 64, true, 1, 0x81).unwrap();

        // IN request carries no data payload: just the 0x30-byte descriptor base.
        assert_eq!(frame.len(), 0x30);
        assert_eq!(frame[0x17], 0x04); // bulk-IN
        assert_eq!(frame[0x15], 0x40); // requested length low byte = 64
        assert_eq!(frame[0x14], 0x00); // high nibble
        assert_eq!(frame[0x20], 0x81); // pipe handle (bulk-IN)
        assert_eq!(frame[0x22], 0x30);
        assert_eq!(frame[0x23], 0xF0);
        assert_eq!(frame[0x24], 0x40);
        assert_eq!(frame[0x25], 0x00);
        assert_eq!(frame[0x18], 0x05); // seq LE
        assert_eq!(frame[0x1E], 0x01);
    }

    #[test]
    fn build_bulk_request_rejects_oversized_single_frame() {
        assert!(matches!(
            build_bulk_request(1, None, 0, 0x1000, true, 1, 0x81),
            Err(TransportError::Protocol(_))
        ));
    }

    /// Bytes 0x20 (pipe handle), 0x22=0x30 and 0x23=0xF0 are the fields the old
    /// builder left zero (GenHC `FUN_0001b110`).
    #[test]
    fn build_bulk_request_writes_handle_and_constants() {
        // Distinct handles flow straight through to byte 0x20 for both directions.
        let out = build_bulk_request(1, Some(&[0x00]), 0, 0, false, 1, 0x01).unwrap();
        assert_eq!(out[0x20], 0x01);
        assert_eq!((out[0x22], out[0x23]), (0x30, 0xF0));

        let inp = build_bulk_request(1, None, 0, 1, true, 1, 0x81).unwrap();
        assert_eq!(inp[0x20], 0x81);
        assert_eq!((inp[0x22], inp[0x23]), (0x30, 0xF0));

        // The handle is whatever the caller passes (not hard-coded by direction).
        let custom = build_bulk_request(1, None, 0, 1, true, 1, 0x05).unwrap();
        assert_eq!(custom[0x20], 0x05);
    }

    /// [`pipe_handle`] matches the GenHC `FUN_0001c104` class rules.
    #[test]
    fn pipe_handle_matches_driver_rules() {
        // PL2303 is vendor-class (0xFF): bulk-OUT (EP2, bulk attr) -> 0x01.
        assert_eq!(pipe_handle(0x02, 0x02, 0xFF), 0x01);
        // PL2303 bulk-IN (EP3) -> 0x81.
        assert_eq!(pipe_handle(0x83, 0x02, 0xFF), 0x81);
        // Non-bulk (interrupt EP1) -> 0x01 regardless of direction.
        assert_eq!(pipe_handle(0x81, 0x03, 0xFF), 0x01);
        // Printer class (7) bulk-OUT -> 0x81; mass-storage (8) bulk-IN -> 0x01.
        assert_eq!(pipe_handle(0x02, 0x02, 7), 0x81);
        assert_eq!(pipe_handle(0x81, 0x02, 8), 0x01);
    }

    /// A PL2303-style configuration descriptor resolves EP2->0x01, EP3->0x81.
    #[test]
    fn parse_config_descriptor_resolves_pl2303_handles() {
        // CONFIGURATION(9) + INTERFACE(9, class 0xFF) + 3 ENDPOINTs:
        //   EP1 interrupt-IN (0x81/0x03), EP2 bulk-OUT (0x02/0x02),
        //   EP3 bulk-IN (0x83/0x02), all wMaxPacketSize 0x40.
        #[rustfmt::skip]
        let desc: &[u8] = &[
            // CONFIGURATION: bLength=9, type=2, wTotalLength=0x2000? -> set to 39 (0x27)
            0x09, 0x02, 0x27, 0x00, 0x01, 0x05, 0x00, 0x80, 0x32,
            // INTERFACE: bLength=9, type=4, #=0, alt=0, nEP=3, class=0xFF, sub=0, proto=0, iIface=0
            0x09, 0x04, 0x00, 0x00, 0x03, 0xFF, 0x00, 0x00, 0x00,
            // ENDPOINT EP1 interrupt-IN: len=7, type=5, addr=0x81, attr=0x03, maxpkt=0x0A,0x00, int=1
            0x07, 0x05, 0x81, 0x03, 0x0A, 0x00, 0x01,
            // ENDPOINT EP2 bulk-OUT: addr=0x02, attr=0x02, maxpkt=0x40,0x00
            0x07, 0x05, 0x02, 0x02, 0x40, 0x00, 0x00,
            // ENDPOINT EP3 bulk-IN: addr=0x83, attr=0x02, maxpkt=0x40,0x00
            0x07, 0x05, 0x83, 0x02, 0x40, 0x00, 0x00,
        ];
        let cfg = parse_config_descriptor(desc).unwrap();
        assert_eq!(cfg.config_value, 0x05);
        assert_eq!(cfg.iface_class, 0xFF);
        assert_eq!(cfg.handles.out, 0x01);
        assert_eq!(cfg.handles.in_, 0x81);
    }

    #[test]
    fn parse_config_descriptor_rejects_non_config() {
        // A device descriptor (type 0x01) is not a configuration descriptor.
        let err = parse_config_descriptor(&ORACLE_DATA).unwrap_err();
        assert!(matches!(err, TransportError::Protocol(_)));
    }

    #[test]
    fn encode_setup_packet_matches_usb_layout() {
        // SET_LINE_CODING for default 9600 8N1: type 0x21, req 0x20, wLength 7.
        let req = pl2303::set_line_coding(&LineCoding::default());
        let setup = encode_setup_packet(&req);
        assert_eq!(setup, [0x21, 0x20, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00]);
    }

    /// LIVE-CONFIRMED claim oracle for device_index=1, seq=1:
    /// `100f0e0d0c0b0a090807060504030201 554e5424 0044 01 0a 0100 80 0000000000 01`
    /// then zero-filled to 116 bytes.
    #[test]
    fn build_claim_matches_live_oracle() {
        let claim = build_claim(1, 1);
        assert_eq!(claim.len(), CLAIM_LEN);
        assert_eq!(claim.len(), 0x74);

        // Bytes 0x00..=0x20 are the only non-zero bytes.
        #[rustfmt::skip]
        let head: [u8; 0x21] = [
            0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09,
            0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, // placeholder
            0x55, 0x4E, 0x54, 0x24,                         // "UNT$"
            0x00, 0x44,                                     // 0x4400 LE @0x14
            0x01,                                           // device index @0x16
            0x0A,                                           // claim type @0x17
            0x01, 0x00,                                     // seq=1 LE @0x18
            0x80,                                           // flag @0x1A
            0x00, 0x00, 0x00, 0x00, 0x00,                   // 0x1B..0x1F
            0x01,                                           // device index @0x20
        ];
        assert_eq!(&claim[..0x21], &head[..]);
        assert!(claim[0x21..].iter().all(|&b| b == 0));
    }

    /// Parse the LIVE-CONFIRMED claim ack and latch the 1460 session frame size.
    #[test]
    fn claim_ack_latches_session_size() {
        // `55 4e 54 24 00 44 00 0b 01 00 80 00 00 00 00 00 01 00 05 b4 00...`
        let mut ack = [0u8; HEADER_LEN];
        ack[0x00..0x04].copy_from_slice(&MAGIC);
        ack[0x04] = 0x00;
        ack[0x05] = 0x44; // payload_len BE = 0x0044
        ack[0x07] = 0x0B; // claim-ack opcode
        ack[0x08] = 0x01; // seq LE = 1
        ack[0x0A] = 0x80;
        ack[0x10] = 0x01; // device index
        ack[0x12] = 0x05;
        ack[0x13] = 0xB4; // session size BE = 0x05B4 = 1460

        let hdr = ResponseHeader::parse(&ack).unwrap();
        assert_eq!(hdr.opcode, OPCODE_CLAIM_ACK);
        assert_eq!(hdr.seq, 1);
        assert_eq!(hdr.value, 0x05B4);
        assert_eq!(session_size_from_ack(&hdr), 0x05B4);
        assert_eq!(session_size_from_ack(&hdr), 1460);
    }

    /// A claim ack with no size field falls back to the 1460 default.
    #[test]
    fn claim_ack_without_size_falls_back_to_default() {
        let mut ack = [0u8; HEADER_LEN];
        ack[0x00..0x04].copy_from_slice(&MAGIC);
        ack[0x07] = 0x0B;
        let hdr = ResponseHeader::parse(&ack).unwrap();
        assert_eq!(hdr.value, 0);
        assert_eq!(session_size_from_ack(&hdr), DEFAULT_SESSION_FRAME_SIZE);
        assert_eq!(DEFAULT_SESSION_FRAME_SIZE, 1460);
    }

    /// Bulk-OUT (EP2) and bulk-IN (EP3) pipe-field encoding (notes §10.4).
    #[test]
    fn build_bulk_request_encodes_endpoint_fields() {
        // Bulk-OUT = EP2: 0x17=0x02, 0x2C=0x40, 0x2E=0x21, 0x2F=0x20, 0x2D=0x00.
        let out = build_bulk_request(1, Some(&[0xAA, 0xBB]), 0, 0, false, 1, 0x01).unwrap();
        assert_eq!(out[0x17], 0x02);
        assert_eq!(out[0x2C], 0x40);
        assert_eq!(out[0x2D], 0x00);
        assert_eq!(out[0x2E], 0x21); // EP nibble 2, device index 1
        assert_eq!(out[0x2F], 0x20);

        // Bulk-IN = EP3: 0x17=0x04, 0x2C=0x40, 0x2E=0x31, 0x2F=0x24, 0x2D=0x00.
        let inp = build_bulk_request(2, None, 0, 64, true, 1, 0x81).unwrap();
        assert_eq!(inp[0x17], 0x04);
        assert_eq!(inp[0x2C], 0x40);
        assert_eq!(inp[0x2D], 0x00);
        assert_eq!(inp[0x2E], 0x31); // EP nibble 3, device index 1
        assert_eq!(inp[0x2F], 0x24);
    }

    /// The device-index low nibble of 0x2E tracks the port.
    #[test]
    fn build_bulk_request_endpoint_nibble_tracks_device_index() {
        let out = build_bulk_request(1, Some(&[0x00]), 0, 0, false, 3, 0x01).unwrap();
        assert_eq!(out[0x2E], 0x23); // EP2 << 4 | (device_index 3 & 0xF)
    }

    /// The keep-alive frame carries type 0x12 and is padded to the frame size.
    #[test]
    fn build_keepalive_layout_and_padding() {
        let frame = build_keepalive(7, 1, 1460);
        assert_eq!(frame.len(), 1460);
        assert_eq!(&frame[0x00..0x10], &PLACEHOLDER_TEMPLATE);
        assert_eq!(&frame[0x10..0x14], b"UNT$");
        assert_eq!(frame[0x16], 0x01); // device index
        assert_eq!(frame[0x17], KEEPALIVE_TYPE); // 0x12
        assert_eq!(frame[0x18], 0x07); // seq LE lo
        assert_eq!(frame[0x19], 0x00); // seq LE hi
        assert_eq!(frame[0x1A], 0x80); // flag
        assert_eq!(frame[0x20], 0x01); // device index
        assert!(frame[0x21..].iter().all(|&b| b == 0));
    }
}
