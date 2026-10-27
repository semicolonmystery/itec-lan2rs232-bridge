//! itec-bridge — direct-IP client/bridge for the ESTI E1868 "Network USB Server"
//! (i-tec LAN2RS232). Cross-platform, no vendor driver.
//!
//! The box shares an internal Prolific PL2303 USB-serial chip over a proprietary
//! USB-over-IP protocol on TCP 4660. This binary is built *around* that (still
//! being reverse-engineered) transport:
//!
//!   * [`transport`] defines the `Transport` seam the real 4660 impl drops into.
//!   * [`pl2303`] encodes the PL2303 control requests from public kernel docs.
//!   * [`server`] is the local TCP endpoint a COM-port shim attaches to.
//!   * [`probe`] is the pre-existing safe, read-only diagnostic subcommand.
//!
//! Subcommands:
//!   itec-bridge bridge --device <ip> [--device-port 4660]
//!                      (--listen <port> | --serial <COMport>) \
//!                      [--baud 9600] [--data 8] [--parity none] [--stop 1] [--real]
//!   itec-bridge probe  <ip> [--port 4660] [--send <hex>] [--secs 6]
//!
//! `--serial` drives a local (virtual com0com) serial port directly, with no
//! external com2tcp/hub4com; `--listen` serves a local TCP port instead. Exactly
//! one of the two must be given.

use std::net::{SocketAddr, ToSocketAddrs};

use clap::{Parser, Subcommand, ValueEnum};

use itec_bridge::transport::{
    DataBits, Esti4660Transport, LineCoding, Parity, StopBits, StubTransport, Transport,
};
use itec_bridge::{probe, server};

/// Default TCP port for the ESTI USB-over-IP channel (0x1234).
const DEFAULT_DEVICE_PORT: u16 = 4660;

#[derive(Parser)]
#[command(
    name = "itec-bridge",
    about = "Direct-IP client/bridge for ESTI E1868 (i-tec LAN2RS232)",
    version
)]
struct Cli {
    #[command(subcommand)]
    command: Command,
}

#[derive(Subcommand)]
enum Command {
    /// Serve a local TCP port and pump bytes to/from the remote serial device.
    Bridge(BridgeArgs),
    /// Read-only diagnostic: connect, optionally send hex once, hexdump replies.
    Probe(ProbeArgs),
}

#[derive(Parser)]
struct BridgeArgs {
    /// IP address of the ESTI box.
    #[arg(long)]
    device: String,
    /// TCP port of the ESTI USB-over-IP channel.
    #[arg(long, default_value_t = DEFAULT_DEVICE_PORT)]
    device_port: u16,
    /// Local TCP port to listen on (what a COM-port shim attaches to).
    /// Mutually exclusive with `--serial`; exactly one must be given.
    #[arg(long, conflicts_with = "serial", required_unless_present = "serial")]
    listen: Option<u16>,
    /// Local serial port to drive directly (e.g. a com0com virtual port:
    /// `\\.\CNCB0` or `COM20` on Windows, `/dev/ttyUSB0` on Unix). Pumps bytes
    /// straight between this port and the device — no external com2tcp/hub4com.
    /// Mutually exclusive with `--listen`; exactly one must be given.
    #[arg(long, conflicts_with = "listen", required_unless_present = "listen")]
    serial: Option<String>,
    /// Serial baud rate.
    #[arg(long, default_value_t = 9600)]
    baud: u32,
    /// Serial data bits (5..=8).
    #[arg(long, default_value_t = 8)]
    data: u8,
    /// Serial parity.
    #[arg(long, value_enum, default_value_t = ParityArg::None)]
    parity: ParityArg,
    /// Serial stop bits.
    #[arg(long, value_enum, default_value_t = StopArg::One)]
    stop: StopArg,
    /// Use the real 4660 transport (connect + session claim + keep-alive) instead
    /// of the stub. Without this flag the bridge wires up a StubTransport so the
    /// plumbing can be exercised without a device.
    #[arg(long)]
    real: bool,
}

#[derive(Parser)]
struct ProbeArgs {
    /// IP address of the ESTI box.
    ip: String,
    /// TCP port.
    #[arg(long, default_value_t = DEFAULT_DEVICE_PORT)]
    port: u16,
    /// Hex bytes to send once before reading (e.g. "00 01 ff").
    #[arg(long)]
    send: Option<String>,
    /// Seconds to read for after connecting/sending.
    #[arg(long, default_value_t = 6)]
    secs: u64,
}

#[derive(Copy, Clone, PartialEq, Eq, ValueEnum)]
enum ParityArg {
    None,
    Odd,
    Even,
    Mark,
    Space,
}

#[derive(Copy, Clone, PartialEq, Eq, ValueEnum)]
enum StopArg {
    #[value(name = "1")]
    One,
    #[value(name = "1.5")]
    OnePointFive,
    #[value(name = "2")]
    Two,
}

fn main() {
    let cli = Cli::parse();
    let result = match cli.command {
        Command::Bridge(args) => run_bridge(args),
        Command::Probe(args) => probe::run(&args.ip, args.port, args.send.as_deref(), args.secs),
    };
    if let Err(e) = result {
        eprintln!("error: {e}");
        std::process::exit(1);
    }
}

fn run_bridge(args: BridgeArgs) -> Result<(), String> {
    let data_bits = match args.data {
        5 => DataBits::Five,
        6 => DataBits::Six,
        7 => DataBits::Seven,
        8 => DataBits::Eight,
        other => return Err(format!("invalid --data {other} (expected 5..=8)")),
    };
    let coding = LineCoding {
        baud: args.baud,
        data_bits,
        parity: match args.parity {
            ParityArg::None => Parity::None,
            ParityArg::Odd => Parity::Odd,
            ParityArg::Even => Parity::Even,
            ParityArg::Mark => Parity::Mark,
            ParityArg::Space => Parity::Space,
        },
        stop_bits: match args.stop {
            StopArg::One => StopBits::One,
            StopArg::OnePointFive => StopBits::OnePointFive,
            StopArg::Two => StopBits::Two,
        },
    };

    let device: SocketAddr = format!("{}:{}", args.device, args.device_port)
        .to_socket_addrs()
        .map_err(|e| e.to_string())?
        .next()
        .ok_or("could not resolve --device address")?;

    let runtime = tokio::runtime::Builder::new_multi_thread()
        .enable_all()
        .build()
        .map_err(|e| e.to_string())?;

    runtime.block_on(async move {
        let transport: Box<dyn Transport> = if args.real {
            eprintln!("connecting to device {device} (real 4660 transport: claim + keep-alive) ...");
            Box::new(Esti4660Transport::connect(device).await.map_err(|e| e.to_string())?)
        } else {
            eprintln!("using StubTransport (pass --real for the 4660 transport)");
            Box::new(StubTransport::new())
        };
        // Exactly one of --serial / --listen is guaranteed by clap (conflict +
        // required_unless_present), so the serial branch wins when set and the
        // TCP branch otherwise.
        if let Some(port) = args.serial {
            eprintln!("serial mode: driving {port} directly (no com2tcp/hub4com)");
            server::run_serial(port, coding.baud, transport, coding)
                .await
                .map_err(|e| e.to_string())
        } else {
            let listen: SocketAddr = ([127, 0, 0, 1], args.listen.expect("clap guarantees one of serial/listen")).into();
            server::run(listen, transport, coding)
                .await
                .map_err(|e| e.to_string())
        }
    })
}

#[cfg(test)]
mod tests {
    use super::*;

    /// Parse a `bridge` invocation from the given extra args (device fixed).
    fn parse(extra: &[&str]) -> Result<Cli, clap::Error> {
        let mut argv = vec!["itec-bridge", "bridge", "--device", "192.168.10.10"];
        argv.extend_from_slice(extra);
        Cli::try_parse_from(argv)
    }

    #[test]
    fn serial_alone_parses() {
        let cli = parse(&["--serial", "COM20"]).expect("--serial alone should parse");
        match cli.command {
            Command::Bridge(a) => {
                assert_eq!(a.serial.as_deref(), Some("COM20"));
                assert_eq!(a.listen, None);
            }
            _ => panic!("expected Bridge"),
        }
    }

    #[test]
    fn listen_alone_parses() {
        let cli = parse(&["--listen", "5000"]).expect("--listen alone should parse");
        match cli.command {
            Command::Bridge(a) => {
                assert_eq!(a.listen, Some(5000));
                assert_eq!(a.serial, None);
            }
            _ => panic!("expected Bridge"),
        }
    }

    #[test]
    fn serial_and_listen_conflict() {
        let err = parse(&["--serial", "COM20", "--listen", "5000"])
            .err()
            .expect("--serial and --listen together must be rejected");
        assert_eq!(err.kind(), clap::error::ErrorKind::ArgumentConflict);
    }

    #[test]
    fn neither_serial_nor_listen_is_error() {
        let err = parse(&[])
            .err()
            .expect("one of --serial/--listen is required");
        assert_eq!(err.kind(), clap::error::ErrorKind::MissingRequiredArgument);
    }
}
