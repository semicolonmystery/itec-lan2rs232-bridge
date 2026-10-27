//! Read-only diagnostic `probe` subcommand (std-only, synchronous).
//!
//! Connects to the ESTI box, optionally sends a hex string once, then reads for
//! a few seconds and hexdumps whatever came back. It never writes device
//! configuration — it is a safe tool for confirming reverse-engineered framing
//! against the live device. Kept independent of the async bridge path.

use std::io::{Read, Write};
use std::net::{TcpStream, ToSocketAddrs};
use std::time::{Duration, Instant};

/// Run the probe. `send_hex` is an optional hex string sent once before reading.
pub fn run(ip: &str, port: u16, send_hex: Option<&str>, secs: u64) -> Result<(), String> {
    let addr = format!("{ip}:{port}");
    let sock = addr
        .to_socket_addrs()
        .map_err(|e| e.to_string())?
        .next()
        .ok_or("could not resolve address")?;

    eprintln!("connecting to {addr} ...");
    let mut stream =
        TcpStream::connect_timeout(&sock, Duration::from_secs(3)).map_err(|e| e.to_string())?;
    stream
        .set_read_timeout(Some(Duration::from_millis(500)))
        .ok();

    if let Some(hex) = send_hex {
        let bytes = parse_hex(hex)?;
        eprintln!("sending {} byte(s): {}", bytes.len(), to_hex(&bytes, " "));
        stream.write_all(&bytes).map_err(|e| e.to_string())?;
        stream.flush().ok();
    } else {
        eprintln!("listen-only (sending nothing)");
    }

    let mut buf = Vec::new();
    let mut tmp = [0u8; 4096];
    let start = Instant::now();
    while start.elapsed() < Duration::from_secs(secs) {
        match stream.read(&mut tmp) {
            Ok(0) => {
                eprintln!("peer closed connection");
                break;
            }
            Ok(n) => buf.extend_from_slice(&tmp[..n]),
            Err(ref e)
                if e.kind() == std::io::ErrorKind::WouldBlock
                    || e.kind() == std::io::ErrorKind::TimedOut => {}
            Err(e) => return Err(e.to_string()),
        }
    }

    eprintln!("received {} byte(s)", buf.len());
    hexdump(&buf);
    Ok(())
}

fn parse_hex(s: &str) -> Result<Vec<u8>, String> {
    let clean: String = s.chars().filter(|c| !c.is_whitespace()).collect();
    if clean.len() % 2 != 0 {
        return Err("hex must have an even number of digits".into());
    }
    (0..clean.len())
        .step_by(2)
        .map(|k| u8::from_str_radix(&clean[k..k + 2], 16).map_err(|_| "bad hex".to_string()))
        .collect()
}

fn to_hex(b: &[u8], sep: &str) -> String {
    b.iter().map(|x| format!("{x:02x}")).collect::<Vec<_>>().join(sep)
}

fn hexdump(data: &[u8]) {
    for (off, chunk) in data.chunks(16).enumerate() {
        let hex = chunk.iter().map(|b| format!("{b:02x}")).collect::<Vec<_>>().join(" ");
        let ascii: String = chunk
            .iter()
            .map(|&b| if (0x20..0x7f).contains(&b) { b as char } else { '.' })
            .collect();
        println!("{:08x}  {:<48}  {}", off * 16, hex, ascii);
    }
}
