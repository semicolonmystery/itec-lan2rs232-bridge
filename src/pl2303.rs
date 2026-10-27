//! Prolific PL2303 USB-serial control encoding.
//!
//! The ESTI E1868 shares an *internal* Prolific PL2303 chip over its proprietary
//! USB-over-IP link. Configuring the serial line therefore means issuing the
//! same USB control transfers the PL2303 host driver would. This module encodes
//! those requests from **public** documentation — the Linux kernel driver
//! `drivers/usb/serial/pl2303.c` (GPL-2.0) — so the real [`crate::transport`]
//! can tunnel them inside the 4660 framing once that format is known.
//!
//! All request codes, structures and the init "magic" below are taken from
//! `drivers/usb/serial/pl2303.c` in the mainline Linux kernel. References are
//! cited inline. Nothing here is specific to the (unknown) 4660 wire format.

use crate::transport::{DataBits, LineCoding, Parity, StopBits};

// --- USB control-request constants (from pl2303.c) -------------------------
//
//   #define SET_LINE_REQUEST_TYPE        0x21
//   #define SET_LINE_REQUEST             0x20
//   #define SET_CONTROL_REQUEST_TYPE     0x21
//   #define SET_CONTROL_REQUEST          0x22
//   #define CONTROL_DTR                  0x01
//   #define CONTROL_RTS                  0x02
//   #define VENDOR_WRITE_REQUEST_TYPE    0x40
//   #define VENDOR_WRITE_REQUEST         0x01
//   #define VENDOR_READ_REQUEST_TYPE     0xc0
//   #define VENDOR_READ_REQUEST          0x01

/// `bmRequestType` for SET_LINE_CODING (host->device, class, interface).
pub const SET_LINE_REQUEST_TYPE: u8 = 0x21;
/// `bRequest` = SET_LINE_CODING.
pub const SET_LINE_REQUEST: u8 = 0x20;

/// `bmRequestType` for SET_CONTROL_LINE_STATE (host->device, class, interface).
pub const SET_CONTROL_REQUEST_TYPE: u8 = 0x21;
/// `bRequest` = SET_CONTROL_LINE_STATE.
pub const SET_CONTROL_REQUEST: u8 = 0x22;
/// `wValue` bit: assert DTR.
pub const CONTROL_DTR: u16 = 0x01;
/// `wValue` bit: assert RTS.
pub const CONTROL_RTS: u16 = 0x02;

/// `bmRequestType` for a Prolific vendor write (host->device, vendor, device).
pub const VENDOR_WRITE_REQUEST_TYPE: u8 = 0x40;
/// `bRequest` for a Prolific vendor write.
pub const VENDOR_WRITE_REQUEST: u8 = 0x01;
/// `bmRequestType` for a Prolific vendor read (device->host, vendor, device).
pub const VENDOR_READ_REQUEST_TYPE: u8 = 0xc0;
/// `bRequest` for a Prolific vendor read.
pub const VENDOR_READ_REQUEST: u8 = 0x01;

// --- SET_LINE_CODING 7-byte structure --------------------------------------
//
// pl2303.c (pl2303_set_termios) fills a 7-byte buffer `buf[0..7]`:
//   buf[0..4] = dwDTERate     (baud, little-endian u32)
//   buf[4]    = bCharFormat   (stop bits: 0 => 1, 1 => 1.5, 2 => 2)
//   buf[5]    = bParityType   (0 none, 1 odd, 2 even, 3 mark, 4 space)
//   buf[6]    = bDataBits     (5, 6, 7 or 8)
// and sends it with SET_LINE_REQUEST / SET_LINE_REQUEST_TYPE.

/// `bCharFormat` values (stop bits), per pl2303.c.
pub mod char_format {
    pub const STOP_BITS_1: u8 = 0;
    pub const STOP_BITS_1_5: u8 = 1;
    pub const STOP_BITS_2: u8 = 2;
}

/// `bParityType` values, per pl2303.c.
pub mod parity_type {
    pub const NONE: u8 = 0;
    pub const ODD: u8 = 1;
    pub const EVEN: u8 = 2;
    pub const MARK: u8 = 3;
    pub const SPACE: u8 = 4;
}

/// A fully-described PL2303 control request ready to be issued as a USB control
/// transfer (and, for the ESTI box, wrapped in the 4660 framing).
///
/// Field names follow the USB setup packet: `bmRequestType`, `bRequest`,
/// `wValue`, `wIndex`, plus an optional `data` stage.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct ControlRequest {
    pub request_type: u8,
    pub request: u8,
    pub value: u16,
    pub index: u16,
    pub data: Vec<u8>,
}

/// Build the 7-byte SET_LINE_CODING data stage for a [`LineCoding`].
///
/// Layout from pl2303.c (`pl2303_set_termios`): see module docs.
pub fn encode_line_coding(coding: &LineCoding) -> [u8; 7] {
    let baud = coding.baud.to_le_bytes();

    let char_format = match coding.stop_bits {
        StopBits::One => char_format::STOP_BITS_1,
        StopBits::OnePointFive => char_format::STOP_BITS_1_5,
        StopBits::Two => char_format::STOP_BITS_2,
    };

    let parity = match coding.parity {
        Parity::None => parity_type::NONE,
        Parity::Odd => parity_type::ODD,
        Parity::Even => parity_type::EVEN,
        Parity::Mark => parity_type::MARK,
        Parity::Space => parity_type::SPACE,
    };

    let data_bits = match coding.data_bits {
        DataBits::Five => 5,
        DataBits::Six => 6,
        DataBits::Seven => 7,
        DataBits::Eight => 8,
    };

    [
        baud[0], baud[1], baud[2], baud[3],
        char_format,
        parity,
        data_bits,
    ]
}

/// Build the SET_LINE_CODING control request for a [`LineCoding`].
pub fn set_line_coding(coding: &LineCoding) -> ControlRequest {
    ControlRequest {
        request_type: SET_LINE_REQUEST_TYPE,
        request: SET_LINE_REQUEST,
        value: 0,
        index: 0,
        data: encode_line_coding(coding).to_vec(),
    }
}

/// Build the SET_CONTROL_LINE_STATE control request for the given DTR/RTS state.
///
/// pl2303.c packs DTR/RTS into `wValue` (CONTROL_DTR | CONTROL_RTS) with no data
/// stage.
pub fn set_control_line_state(dtr: bool, rts: bool) -> ControlRequest {
    let mut value = 0u16;
    if dtr {
        value |= CONTROL_DTR;
    }
    if rts {
        value |= CONTROL_RTS;
    }
    ControlRequest {
        request_type: SET_CONTROL_REQUEST_TYPE,
        request: SET_CONTROL_REQUEST,
        value,
        index: 0,
        data: Vec::new(),
    }
}

/// One step of the PL2303 power-on init "magic".
///
/// `read` steps issue a VENDOR_READ (device->host); `write` steps issue a
/// VENDOR_WRITE (host->device). `value`/`index` are the setup-packet `wValue`/
/// `wIndex`.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum InitStep {
    Read { value: u16 },
    Write { value: u16, index: u16 },
}

impl InitStep {
    /// Expand this step into a concrete [`ControlRequest`] (a vendor read has a
    /// 1-byte IN data stage; a vendor write carries no data).
    pub fn to_request(self) -> ControlRequest {
        match self {
            InitStep::Read { value } => ControlRequest {
                request_type: VENDOR_READ_REQUEST_TYPE,
                request: VENDOR_READ_REQUEST,
                value,
                index: 0,
                data: vec![0u8; 1],
            },
            InitStep::Write { value, index } => ControlRequest {
                request_type: VENDOR_WRITE_REQUEST_TYPE,
                request: VENDOR_WRITE_REQUEST,
                value,
                index,
                data: Vec::new(),
            },
        }
    }
}

/// The classic PL2303 reset / init "magic" sequence, from pl2303.c
/// (`pl2303_startup` in older kernels; the vendor read/write dance that
/// initialises the chip). The final `Write { value: 2, index: 0x44 }` is the
/// non-HX variant; HX-type chips use index `0x24`.
///
/// These are issued once after attach, before SET_LINE_CODING. Source:
/// drivers/usb/serial/pl2303.c (GPL-2.0).
pub const INIT_MAGIC: &[InitStep] = &[
    InitStep::Read { value: 0x8484 },
    InitStep::Write { value: 0x0404, index: 0 },
    InitStep::Read { value: 0x8484 },
    InitStep::Read { value: 0x8383 },
    InitStep::Read { value: 0x8484 },
    InitStep::Write { value: 0x0404, index: 1 },
    InitStep::Read { value: 0x8484 },
    InitStep::Read { value: 0x8383 },
    InitStep::Write { value: 0, index: 1 },
    InitStep::Write { value: 1, index: 0 },
    InitStep::Write { value: 2, index: 0x44 },
];

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn default_9600_8n1_encodes_as_expected() {
        // 9600 = 0x2580 => little-endian 80 25 00 00; 8N1 => 00 00 08.
        let buf = encode_line_coding(&LineCoding::default());
        assert_eq!(buf, [0x80, 0x25, 0x00, 0x00, 0x00, 0x00, 0x08]);
    }

    #[test]
    fn stop_and_parity_and_data_bits_map() {
        let coding = LineCoding {
            baud: 115_200,
            data_bits: DataBits::Seven,
            parity: Parity::Even,
            stop_bits: StopBits::Two,
        };
        let buf = encode_line_coding(&coding);
        // 115200 = 0x1C200 => 00 C2 01 00
        assert_eq!(&buf[0..4], &[0x00, 0xC2, 0x01, 0x00]);
        assert_eq!(buf[4], char_format::STOP_BITS_2);
        assert_eq!(buf[5], parity_type::EVEN);
        assert_eq!(buf[6], 7);
    }

    #[test]
    fn control_line_state_bits() {
        assert_eq!(set_control_line_state(true, true).value, 0x03);
        assert_eq!(set_control_line_state(true, false).value, 0x01);
        assert_eq!(set_control_line_state(false, false).value, 0x00);
    }
}
