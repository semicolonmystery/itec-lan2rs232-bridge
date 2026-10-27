//! itec-bridge — library crate for the ESTI E1868 "Network USB Server"
//! (i-tec LAN2RS232) direct-IP bridge.
//!
//! The ESTI box shares an internal Prolific PL2303 USB-serial chip over a
//! proprietary USB-over-IP protocol on TCP 4660. This crate is built *around*
//! that (still being reverse-engineered) transport so the real wire format can
//! drop into a clean seam:
//!
//!   * [`transport`] — the `Transport` seam (trait + [`transport::LineCoding`]),
//!     a [`transport::StubTransport`] placeholder, and the skeleton
//!     [`transport::Esti4660Transport`].
//!   * [`pl2303`] — PL2303 control-request encoding from public kernel docs.
//!   * [`server`] — the local TCP endpoint a COM-port shim attaches to.
//!   * [`probe`] — the safe, read-only diagnostic used during RE.

pub mod logging;
pub mod pl2303;
pub mod probe;
pub mod server;
pub mod transport;
