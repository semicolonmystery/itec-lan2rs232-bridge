//! Log sink seam.
//!
//! The bridge's user-facing progress/error lines go through [`emit`] (via the
//! [`crate::log_line!`] macro) instead of `eprintln!` directly. By default
//! `emit` prints to stderr — exactly the CLI's existing behaviour. A front-end
//! (the GUI) can install an [`std::sync::mpsc`] channel with [`set_sink`] to
//! capture those lines and display them instead; [`clear_sink`] restores the
//! stderr path.
//!
//! One process-wide sink is enough: the app runs a single bridge at a time.

use std::sync::mpsc::Sender;
use std::sync::{Mutex, OnceLock};

static SINK: OnceLock<Mutex<Option<Sender<String>>>> = OnceLock::new();

fn sink() -> &'static Mutex<Option<Sender<String>>> {
    SINK.get_or_init(|| Mutex::new(None))
}

/// Install a channel that receives every library log line. Replaces any prior
/// sink. While set, [`emit`] sends to this channel instead of writing stderr.
pub fn set_sink(tx: Sender<String>) {
    if let Ok(mut g) = sink().lock() {
        *g = Some(tx);
    }
}

/// Remove the sink; subsequent [`emit`] calls print to stderr again.
pub fn clear_sink() {
    if let Ok(mut g) = sink().lock() {
        *g = None;
    }
}

/// Emit one log line: to the installed sink if any (falling back to stderr if
/// the channel's receiver has been dropped), else straight to stderr.
pub fn emit(msg: String) {
    if let Ok(g) = sink().lock() {
        if let Some(tx) = g.as_ref() {
            if tx.send(msg.clone()).is_ok() {
                return;
            }
        }
    }
    eprintln!("{msg}");
}

/// Emit a formatted log line through [`emit`]. Drop-in for `eprintln!` for the
/// bridge's user-facing messages.
#[macro_export]
macro_rules! log_line {
    ($($arg:tt)*) => {
        $crate::logging::emit(format!($($arg)*))
    };
}
