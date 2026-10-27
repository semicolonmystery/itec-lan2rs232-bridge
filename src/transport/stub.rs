//! A [`Transport`] placeholder used until the 4660 wire format is known.
//!
//! Every operation fails with [`TransportError::NotImplemented`]. This lets the
//! rest of the application (CLI, local TCP endpoint, PL2303 encoding) be built,
//! wired together and tested end to end before the proprietary USB-over-IP
//! protocol has been reverse-engineered.

use super::{LineCoding, Transport, TransportError};

/// A transport that is connected in name only: it refuses every operation with
/// a clear "not yet implemented" error.
#[derive(Debug, Default)]
pub struct StubTransport {
    /// Remembered so diagnostics can show what the caller *would* have sent.
    last_coding: Option<LineCoding>,
}

impl StubTransport {
    pub fn new() -> Self {
        StubTransport { last_coding: None }
    }

    /// The most recent line coding requested (handy in tests/diagnostics).
    pub fn last_coding(&self) -> Option<LineCoding> {
        self.last_coding
    }
}

#[async_trait::async_trait]
impl Transport for StubTransport {
    async fn set_line_coding(&mut self, coding: LineCoding) -> Result<(), TransportError> {
        self.last_coding = Some(coding);
        Err(TransportError::NotImplemented(
            "StubTransport::set_line_coding — 4660 transport pending (see notes/genhc_protocol.md)",
        ))
    }

    async fn write(&mut self, _data: &[u8]) -> Result<usize, TransportError> {
        Err(TransportError::NotImplemented(
            "StubTransport::write — 4660 transport pending (see notes/genhc_protocol.md)",
        ))
    }

    async fn read(&mut self, _buf: &mut [u8]) -> Result<usize, TransportError> {
        Err(TransportError::NotImplemented(
            "StubTransport::read — 4660 transport pending (see notes/genhc_protocol.md)",
        ))
    }
}
