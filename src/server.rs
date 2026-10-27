//! Local TCP endpoint.
//!
//! Listens on a local port and pumps bytes bidirectionally between the accepted
//! client socket and a [`Transport`]. A Windows COM port (com0com + com2tcp, or
//! HW VSP3) or a Unix PTY (socat) can attach to this port and expose the remote
//! serial device as a local serial port. One client at a time.

use std::io::{Read, Write};
use std::net::SocketAddr;
use std::time::Duration;

use tokio::io::{AsyncReadExt, AsyncWriteExt};
use tokio::net::{TcpListener, TcpStream};
use tokio::sync::{mpsc, watch};

use crate::log_line;
use crate::transport::{DataBits, LineCoding, Parity, StopBits, Transport, TransportError};

/// A programmatic shutdown handle for the bridge loops.
///
/// The CLI drives this from `Ctrl-C` (see [`run`] / [`run_serial`]); the GUI
/// drives it from its Stop button. Holds a `watch::Receiver<bool>`; the loops
/// stop promptly once the paired sender publishes `true` (or is dropped).
pub type Shutdown = watch::Receiver<bool>;

/// Resolve once the shutdown signal is raised (`true`) or the sender is dropped.
/// Cheap to poll; also used via `*rx.borrow()` for an immediate non-blocking
/// check inside the tight pump loops.
async fn wait_shutdown(rx: &mut Shutdown) {
    if *rx.borrow() {
        return;
    }
    while rx.changed().await.is_ok() {
        if *rx.borrow() {
            return;
        }
    }
    // Sender dropped: treat as a shutdown request.
}

/// Spawn a task that raises `shutdown` on `Ctrl-C`, returning the receiver.
/// This is the CLI's shutdown source; the bridge loops themselves only ever
/// see a [`Shutdown`], so the GUI can supply its own.
fn ctrl_c_shutdown() -> Shutdown {
    let (tx, rx) = watch::channel(false);
    tokio::spawn(async move {
        if tokio::signal::ctrl_c().await.is_ok() {
            let _ = tx.send(true);
        }
    });
    rx
}

/// How long each half-duplex poll waits before giving the other direction a
/// turn. The [`Transport`] is a single `&mut` object, so the two directions are
/// serviced alternately rather than as two concurrent tasks; a real duplex
/// transport can later be split to remove this. Kept small so latency stays low.
const POLL_INTERVAL: Duration = Duration::from_millis(50);

/// Render bytes as space-separated lowercase hex for the `ITEC_DEBUG` traces.
fn hex_bytes(bytes: &[u8]) -> String {
    use std::fmt::Write as _;
    let mut s = String::with_capacity(bytes.len() * 3);
    for b in bytes {
        let _ = write!(s, "{b:02x} ");
    }
    s
}

/// Run the local endpoint: bind `listen`, apply `coding` to `transport`, then
/// serve clients one at a time until Ctrl-C. CLI entry point.
pub async fn run(
    listen: SocketAddr,
    transport: Box<dyn Transport>,
    coding: LineCoding,
) -> Result<(), TransportError> {
    run_with_shutdown(listen, transport, coding, ctrl_c_shutdown()).await
}

/// As [`run`], but stopped by a programmatic [`Shutdown`] signal instead of
/// Ctrl-C (the GUI's entry point). Serves clients one at a time; the shutdown
/// is observed both between clients (in the accept loop) and promptly inside an
/// active [`pump`].
pub async fn run_with_shutdown(
    listen: SocketAddr,
    mut transport: Box<dyn Transport>,
    coding: LineCoding,
    mut shutdown: Shutdown,
) -> Result<(), TransportError> {
    // Configure the serial line up front. Surfaced (not swallowed) so the
    // StubTransport's "not implemented" is obvious to the user.
    if let Err(e) = transport.set_line_coding(coding).await {
        log_line!("warning: set_line_coding failed: {e}");
    }

    let listener = TcpListener::bind(listen).await?;
    log_line!("listening on {}", listener.local_addr()?);

    loop {
        tokio::select! {
            accepted = listener.accept() => {
                let (sock, peer) = accepted?;
                log_line!("client connected: {peer}");
                if let Err(e) = pump(sock, transport.as_mut(), &mut shutdown).await {
                    log_line!("client session ended: {e}");
                } else {
                    log_line!("client disconnected: {peer}");
                }
            }
            _ = wait_shutdown(&mut shutdown) => {
                log_line!("shutting down");
                return Ok(());
            }
        }
    }
}

/// Pump bytes between one client socket and the transport until either side
/// closes or `shutdown` is raised. Half-duplex alternation (see [`POLL_INTERVAL`]).
async fn pump(
    sock: TcpStream,
    transport: &mut dyn Transport,
    shutdown: &mut Shutdown,
) -> Result<(), TransportError> {
    let (mut rd, mut wr) = sock.into_split();
    let mut from_client = [0u8; 4096];
    let mut from_device = [0u8; 4096];

    loop {
        // Stop promptly when the GUI (or Ctrl-C) asks us to, even mid-session.
        if *shutdown.borrow() {
            return Ok(());
        }
        let mut idle = true;

        // Client -> device.
        match tokio::time::timeout(POLL_INTERVAL, rd.read(&mut from_client)).await {
            Ok(Ok(0)) => return Ok(()), // client socket actually closed (TCP EOF)
            Ok(Ok(n)) => {
                idle = false;
                if std::env::var_os("ITEC_DEBUG").is_some() {
                    let hex = hex_bytes(&from_client[..n]);
                    log_line!("[LOCAL->DEV] {n} bytes: {hex}");
                }
                let mut sent = 0;
                while sent < n {
                    sent += transport.write(&from_client[sent..n]).await?;
                }
            }
            Ok(Err(e)) => return Err(TransportError::Io(e)),
            Err(_) => {} // nothing from client this tick
        }

        // Device -> client.
        // NOTE: a 0-length read from the transport means "no serial data available
        // right now" — the remote UART simply had nothing to send this tick. It is
        // NOT a closed connection (that surfaces as TransportError::Closed below).
        // Returning early on 0 here would tear the session down on every idle poll.
        match tokio::time::timeout(POLL_INTERVAL, transport.read(&mut from_device)).await {
            Ok(Ok(0)) => {} // no serial data this tick
            Ok(Ok(n)) => {
                idle = false;
                if std::env::var_os("ITEC_DEBUG").is_some() {
                    let hex = hex_bytes(&from_device[..n]);
                    log_line!("[DEV->LOCAL] {n} bytes: {hex}");
                }
                wr.write_all(&from_device[..n]).await.map_err(TransportError::Io)?;
            }
            Ok(Err(e)) => return Err(e),
            Err(_) => {} // transport read timed out this tick
        }

        // Avoid hammering the device with back-to-back bulk-IN polls when both
        // directions are quiet; small enough to stay well under serial latencies.
        if idle {
            tokio::time::sleep(Duration::from_millis(5)).await;
        }
    }
}

// --- Serial mode (--serial) ---------------------------------------------------
//
// Drives a local (typically virtual com0com) serial port directly, bridging it
// to the `Transport` with no external com2tcp/hub4com. The pump mirrors the TCP
// `pump` above (half-duplex alternation, 0 = no data keep polling, small idle
// sleep) but bridges the *blocking* `serialport` crate to the *async* transport
// through a dedicated blocking thread and two mpsc channels:
//
//   blocking serial thread  --[Vec<u8>]-->  async pump  (serial RX -> transport.write)
//   async pump              --[Vec<u8>]-->  blocking serial thread  (transport.read -> serial TX)
//
// One task owns the `Transport` and alternately (a) drains serial-RX bytes and
// `transport.write`s them, (b) `transport.read`s and queues bytes for serial TX.
// The serial thread does the actual blocking port read (50 ms timeout) / write
// against the channels. Dropping either channel end tears the whole thing down.

/// Channel capacity (messages, each a `Vec<u8>` chunk) between the serial thread
/// and the transport pump. Small: enough to decouple the two without unbounded
/// buffering.
const SERIAL_CHANNEL_CAP: usize = 64;

/// Blocking read timeout on the serial port. Short so the serial thread stays
/// responsive to queued serial-TX writes; a timeout is treated as "no data".
const SERIAL_READ_TIMEOUT: Duration = Duration::from_millis(50);

/// Normalize a serial port name for the platform. On Windows, a bare `COMnn`
/// (nn >= 10) must be opened as `\\.\COMnn`; the prefix is also valid for COM1-9,
/// so apply it to any un-prefixed `COM<digits>` name. Other names (already
/// prefixed, or Unix `/dev/...`) pass through unchanged.
fn normalize_serial_name(name: &str) -> String {
    if cfg!(windows)
        && !name.starts_with(r"\\.\")
        && name.len() > 3
        && name[..3].eq_ignore_ascii_case("COM")
        && name[3..].chars().all(|c| c.is_ascii_digit())
    {
        format!(r"\\.\{name}")
    } else {
        name.to_string()
    }
}

/// Run serial mode: open `port_name` at `baud`/8N1, set the real line speed on
/// the device via `transport.set_line_coding(coding)`, then pump bytes
/// bidirectionally between the serial port and the transport until a real
/// serial/transport error or EOF.
///
/// `baud` configures the local (virtual) serial port only; the REAL line speed
/// is carried by `coding` and applied to the device through the transport — the
/// serial port's own baud/line settings are cosmetic for a com0com port.
pub async fn run_serial(
    port_name: String,
    baud: u32,
    transport: Box<dyn Transport>,
    coding: LineCoding,
) -> Result<(), TransportError> {
    run_serial_with_shutdown(port_name, baud, transport, coding, ctrl_c_shutdown()).await
}

/// As [`run_serial`], but stopped by a programmatic [`Shutdown`] signal instead
/// of Ctrl-C (the GUI's entry point). The resilient reopen logic in
/// [`serial_io`] is untouched; the shutdown is observed inside [`serial_pump`],
/// whose return drops the channels and lets the blocking serial thread exit.
pub async fn run_serial_with_shutdown(
    port_name: String,
    baud: u32,
    mut transport: Box<dyn Transport>,
    coding: LineCoding,
    mut shutdown: Shutdown,
) -> Result<(), TransportError> {
    // Accept a bare "COM21" and normalize to the Windows device path. COM ports
    // numbered >= 10 must be opened as "\\.\COM21"; doing this in code means the
    // CLI takes a plain name that no shell can mangle via backslash escaping.
    let port_name = normalize_serial_name(&port_name);

    // Configure the serial line on the device up front (same as the TCP path).
    if let Err(e) = transport.set_line_coding(coding).await {
        log_line!("warning: set_line_coding failed: {e}");
    }

    // serial RX -> transport.write (bulk-OUT to the device).
    let (to_dev_tx, to_dev_rx) = mpsc::channel::<Vec<u8>>(SERIAL_CHANNEL_CAP);
    // transport.read (bulk-IN) -> serial TX.
    let (to_ser_tx, to_ser_rx) = mpsc::channel::<Vec<u8>>(SERIAL_CHANNEL_CAP);

    // Blocking serial port I/O runs on a dedicated blocking thread so it never
    // stalls the tokio reactor.
    let port_for_thread = port_name.clone();
    let serial_thread = tokio::task::spawn_blocking(move || {
        serial_io(&port_for_thread, baud, coding, to_dev_tx, to_ser_rx)
    });

    log_line!("serial mode: pumping {port_name} <-> device");

    // Drive the transport until shutdown, a transport error, or the serial
    // thread ending (both channels close). `serial_pump` itself watches the
    // shutdown signal so an in-flight bulk-IN cannot delay the stop.
    let pump_result = serial_pump(transport.as_mut(), to_dev_rx, to_ser_tx, &mut shutdown).await;

    // The pump owns both of its channel ends; returning from `serial_pump`
    // dropped them, so the serial thread's next read/write observes a closed
    // channel and exits. Join it to surface a port-open / I/O error.
    let serial_result = match serial_thread.await {
        Ok(r) => r,
        Err(join_err) => Err(TransportError::Protocol(format!(
            "serial thread panicked: {join_err}"
        ))),
    };

    // A transport error is the primary failure; otherwise surface any serial
    // error (e.g. the port failed to open).
    pump_result.and(serial_result)
}

/// The async half of serial mode: owns the `Transport` and alternates between
/// draining serial-RX bytes (writing them to the device) and reading device
/// bytes (queuing them for serial TX). Mirrors [`pump`]'s half-duplex loop.
///
/// Returns `Ok(())` when the serial thread has gone away (either channel
/// closed), or a [`TransportError`] on a real transport failure.
async fn serial_pump(
    transport: &mut dyn Transport,
    mut to_dev_rx: mpsc::Receiver<Vec<u8>>,
    to_ser_tx: mpsc::Sender<Vec<u8>>,
    shutdown: &mut Shutdown,
) -> Result<(), TransportError> {
    let debug = std::env::var_os("ITEC_DEBUG").is_some();
    let mut from_device = [0u8; 4096];

    loop {
        // Stop promptly when the GUI (or Ctrl-C) asks us to. Returning here
        // drops both channel ends, so the blocking serial thread exits too.
        if *shutdown.borrow() {
            return Ok(());
        }
        let mut idle = true;

        // Serial -> device: drain whatever the serial thread has queued without
        // blocking (its bytes already arrived off the wire).
        match to_dev_rx.try_recv() {
            Ok(bytes) => {
                idle = false;
                if debug {
                    let hex = hex_bytes(&bytes);
                    log_line!("[SERIAL->DEV] {} bytes: {hex}", bytes.len());
                }
                let mut sent = 0;
                while sent < bytes.len() {
                    sent += transport.write(&bytes[sent..]).await?;
                }
            }
            Err(mpsc::error::TryRecvError::Empty) => {}
            // Serial thread ended (port closed / open failed): stop the pump and
            // let `run_serial` surface the serial result.
            Err(mpsc::error::TryRecvError::Disconnected) => return Ok(()),
        }

        // Device -> serial. A 0-length transport read means "no serial data this
        // tick" (see `pump`); the timeout keeps the loop servicing serial-RX
        // promptly rather than blocking on a bulk-IN that may never complete.
        match tokio::time::timeout(POLL_INTERVAL, transport.read(&mut from_device)).await {
            Ok(Ok(0)) => {} // no serial data this tick
            Ok(Ok(n)) => {
                idle = false;
                if debug {
                    let hex = hex_bytes(&from_device[..n]);
                    log_line!("[DEV->SERIAL] {n} bytes: {hex}");
                }
                if to_ser_tx.send(from_device[..n].to_vec()).await.is_err() {
                    return Ok(()); // serial thread gone
                }
            }
            Ok(Err(e)) => return Err(e),
            Err(_) => {} // transport read timed out this tick
        }

        if idle {
            tokio::time::sleep(Duration::from_millis(5)).await;
        }
    }
}

/// Open the local serial port at the requested baud/line settings. The baud/line
/// settings are cosmetic for a virtual (com0com/Eltima) port — the real line
/// speed is set on the device — but we honour them for tidiness.
fn open_serial_port(
    port_name: &str,
    baud: u32,
    coding: LineCoding,
) -> serialport::Result<Box<dyn serialport::SerialPort>> {
    serialport::new(port_name, baud)
        .data_bits(match coding.data_bits {
            DataBits::Five => serialport::DataBits::Five,
            DataBits::Six => serialport::DataBits::Six,
            DataBits::Seven => serialport::DataBits::Seven,
            DataBits::Eight => serialport::DataBits::Eight,
        })
        .parity(match coding.parity {
            Parity::None => serialport::Parity::None,
            Parity::Odd => serialport::Parity::Odd,
            // serialport has no Mark/Space parity; map them to the nearest
            // supported setting. These are cosmetic for a virtual port.
            Parity::Even | Parity::Mark | Parity::Space => serialport::Parity::Even,
        })
        .stop_bits(match coding.stop_bits {
            // serialport models only 1 or 2 stop bits; 1.5 falls back to 1.
            StopBits::One | StopBits::OnePointFive => serialport::StopBits::One,
            StopBits::Two => serialport::StopBits::Two,
        })
        .timeout(SERIAL_READ_TIMEOUT)
        .open()
}

/// The blocking half of serial mode: open the port and shuttle bytes between it
/// and the two channels. Runs on a `spawn_blocking` thread.
///
/// Loop: read the port with a short timeout (timeout = no data), forwarding any
/// bytes to the device via `to_dev`; then drain all pending device bytes from
/// `from_dev` and write them to the port. Ends (Ok) when either channel closes,
/// or (Err) on a port-open or non-timeout I/O error.
fn serial_io(
    port_name: &str,
    baud: u32,
    coding: LineCoding,
    to_dev: mpsc::Sender<Vec<u8>>,
    mut from_dev: mpsc::Receiver<Vec<u8>>,
) -> Result<(), TransportError> {
    let debug = std::env::var_os("ITEC_DEBUG").is_some();
    let mut buf = [0u8; 4096];
    let mut first = true;

    // Outer "session" loop: (re)open the port, pump until a serial I/O error, then
    // reopen. A paired virtual port (com0com/Eltima) raises transient errors such
    // as ERROR_ACCESS_DENIED (os error 5) when the other app (VisiLogic) opens or
    // closes its end; recover by reopening instead of tearing the bridge down.
    'session: loop {
        let mut port = match open_serial_port(port_name, baud, coding) {
            Ok(p) => {
                first = false;
                p
            }
            Err(e) => {
                // First attempt failing is a real config error (e.g. bad name);
                // a later failure just means the port is momentarily unavailable.
                if first {
                    return Err(TransportError::Protocol(format!(
                        "failed to open serial port {port_name}: {e}"
                    )));
                }
                if to_dev.is_closed() {
                    return Ok(()); // pump gone
                }
                if debug {
                    log_line!("[ITEC_DEBUG] serial reopen of {port_name} failed: {e}; retrying");
                }
                std::thread::sleep(Duration::from_millis(200));
                continue 'session;
            }
        };

        loop {
            // Serial -> device.
            match port.read(&mut buf) {
                Ok(0) => {}
                Ok(n) => {
                    if to_dev.blocking_send(buf[..n].to_vec()).is_err() {
                        return Ok(()); // pump gone
                    }
                }
                Err(e) if e.kind() == std::io::ErrorKind::TimedOut => {} // no data this tick
                Err(e) => {
                    if debug {
                        log_line!("[ITEC_DEBUG] serial read on {port_name}: {e}; reopening");
                    }
                    std::thread::sleep(Duration::from_millis(100));
                    continue 'session;
                }
            }

            // Device -> serial: write everything queued, without blocking.
            loop {
                match from_dev.try_recv() {
                    Ok(bytes) => {
                        if let Err(e) = port.write_all(&bytes) {
                            if debug {
                                log_line!("[ITEC_DEBUG] serial write on {port_name}: {e}; reopening");
                            }
                            std::thread::sleep(Duration::from_millis(100));
                            continue 'session;
                        }
                    }
                    Err(mpsc::error::TryRecvError::Empty) => break,
                    Err(mpsc::error::TryRecvError::Disconnected) => return Ok(()), // pump gone
                }
            }
        }
    }
}
