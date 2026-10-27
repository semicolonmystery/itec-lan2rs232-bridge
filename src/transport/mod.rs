//! Transport seam.
//!
//! A [`Transport`] represents an *already-established* link to the remote
//! serial device exposed by the ESTI E1868 "Network USB Server". Everything in
//! this crate is built around this trait so that the real USB-over-IP wire
//! format (TCP 4660) can drop in as a single `impl Transport` once the protocol
//! reverse-engineering effort lands.
//!
//! The trait deliberately speaks in terms of the *serial line* (line coding,
//! read/write bytes), not the USB-over-IP framing. The concrete transport is
//! responsible for translating these operations into whatever the 4660 wire
//! format turns out to be.

use std::fmt;

pub mod esti4660;
pub mod stub;

pub use esti4660::Esti4660Transport;
pub use stub::StubTransport;

/// Number of data bits on the serial line.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum DataBits {
    Five,
    Six,
    Seven,
    Eight,
}

impl DataBits {
    /// Raw count (5..=8), as used by the PL2303 line-coding structure.
    pub fn as_u8(self) -> u8 {
        match self {
            DataBits::Five => 5,
            DataBits::Six => 6,
            DataBits::Seven => 7,
            DataBits::Eight => 8,
        }
    }
}

/// Parity mode on the serial line.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Parity {
    None,
    Odd,
    Even,
    Mark,
    Space,
}

/// Stop bits on the serial line.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum StopBits {
    One,
    /// 1.5 stop bits (only meaningful with 5 data bits on most UARTs).
    OnePointFive,
    Two,
}

/// A full serial line configuration: baud rate, data bits, parity, stop bits.
///
/// This is the device-agnostic description. [`crate::pl2303`] turns it into the
/// PL2303 `SET_LINE_CODING` byte structure.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct LineCoding {
    pub baud: u32,
    pub data_bits: DataBits,
    pub parity: Parity,
    pub stop_bits: StopBits,
}

impl Default for LineCoding {
    /// 9600 8N1 — the project default.
    fn default() -> Self {
        LineCoding {
            baud: 9600,
            data_bits: DataBits::Eight,
            parity: Parity::None,
            stop_bits: StopBits::One,
        }
    }
}

/// Errors surfaced by a [`Transport`].
#[derive(Debug)]
pub enum TransportError {
    /// The concrete transport (or one of its operations) is not implemented yet.
    NotImplemented(&'static str),
    /// An underlying I/O error (socket, etc.).
    Io(std::io::Error),
    /// The remote end closed the link.
    Closed,
    /// A protocol-level failure once the 4660 format is known.
    Protocol(String),
}

impl fmt::Display for TransportError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            TransportError::NotImplemented(what) => {
                write!(f, "protocol not yet implemented: {what}")
            }
            TransportError::Io(e) => write!(f, "io error: {e}"),
            TransportError::Closed => write!(f, "transport closed by remote"),
            TransportError::Protocol(m) => write!(f, "protocol error: {m}"),
        }
    }
}

impl std::error::Error for TransportError {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        match self {
            TransportError::Io(e) => Some(e),
            _ => None,
        }
    }
}

impl From<std::io::Error> for TransportError {
    fn from(e: std::io::Error) -> Self {
        TransportError::Io(e)
    }
}

/// An established link to the remote serial device.
///
/// Implementors own whatever connection state is needed (e.g. a TCP socket to
/// the ESTI box). The bridge server ([`crate::server`]) drives a `Transport`
/// without knowing anything about the wire format.
///
/// `async_trait` is used so the trait is object-safe (`Box<dyn Transport>`):
/// native `async fn` in traits is stable on 1.75 but not yet usable through
/// `dyn`.
#[async_trait::async_trait]
pub trait Transport: Send {
    /// Apply a serial line configuration (baud, data bits, parity, stop bits).
    ///
    /// For the real device this maps onto the PL2303 `SET_LINE_CODING` /
    /// `SET_CONTROL_LINE_STATE` control requests encoded in [`crate::pl2303`],
    /// tunnelled over the 4660 transport.
    async fn set_line_coding(&mut self, coding: LineCoding) -> Result<(), TransportError>;

    /// Write bytes to the serial line. Returns the number of bytes accepted.
    async fn write(&mut self, data: &[u8]) -> Result<usize, TransportError>;

    /// Read bytes from the serial line into `buf`. Returns the number of bytes
    /// read; `Ok(0)` means the link is at end-of-stream.
    async fn read(&mut self, buf: &mut [u8]) -> Result<usize, TransportError>;
}
