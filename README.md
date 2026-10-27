# itec-lan2rs232-bridge

A direct-IP client for the **i-tec LAN2RS232** network serial server (OEM: Elite Silicon
Technology "ESTI" E1868 *Network USB Server*). It implements the device's USB-over-IP protocol so
the shared serial port can be used over the network by IP address, without the vendor's Windows
client and without relying on multicast discovery (which does not cross VLANs).

The device exposes an internal Prolific PL2303 USB-to-serial chip over TCP port 4660. This project
speaks that protocol directly and presents the serial line locally as either a COM port or a raw
TCP endpoint.

## How it works

```
  your app  ->  virtual COM  ->  itec-bridge  ->  TCP 4660  ->  ESTI device  ->  PL2303  ->  RS-232
 (e.g. PLC      (OS / driver     (this tool)                     (192.168.x.x)
  software)      provides it)
```

`itec-bridge` opens a TCP connection to the device, performs the session claim and USB
enumeration, initialises the PL2303, and then relays serial bytes between the device and a local
endpoint. The protocol is documented in
[`reverse-engineering/PROTOCOL.md`](reverse-engineering/PROTOCOL.md).

## Requirements

The bridge itself needs nothing beyond the binary. Presenting its output as a *serial port*
depends on the operating system:

- **Windows** has no built-in virtual serial port, so a virtual COM-port driver is required. A
  pair of linked ports is created (the application opens one, the bridge drives the other).
  - [Eltima Virtual Serial Port Driver (VSPD)](https://www.eltima.com/products/vspdxp/) works on
    Windows 11 (its driver is Microsoft-signed).
  - [com0com](https://sourceforge.net/projects/com0com/) is free, but its driver is commonly
    blocked by Windows 11 driver-signature enforcement (Code 52).
- **Linux / macOS** need no driver — the OS provides PTYs. Run the bridge in TCP mode and expose a
  PTY with `socat` (see below), or point a TCP-capable application straight at the endpoint.

## Installation

Download a build for your platform from the [Releases](../../releases) page, or build from source:

```
cargo build --release
# binaries: target/release/itec-bridge      (CLI)
#           target/release/itec-bridge-gui   (GUI)
```

## Usage

### Windows (virtual COM pair)

1. Create a linked virtual COM pair in your driver, e.g. `COM16 <-> COM21`.
2. Start the bridge on the bridge-side port:

   - GUI: run `itec-bridge-gui`, set the device IP, select **Serial** and the bridge-side port,
     set the baud rate, and click **Start**.
   - CLI:
     ```
     itec-bridge bridge --device 192.168.10.10 --serial COM21 --real --baud 57600
     ```

3. Open the other port (`COM16`) in your application.

### Linux / macOS (PTY via socat)

```
itec-bridge bridge --device 192.168.10.10 --listen 5660 --real --baud 57600 &
socat pty,link=/dev/ttyV0,raw,echo=0 tcp:127.0.0.1:5660
# open /dev/ttyV0 in your application
```

## Options

```
itec-bridge bridge --device <ip> [--device-port 4660]
                   (--serial <port> | --listen <tcp-port>)
                   [--baud 9600] [--data 8] [--parity none] [--stop 1] --real

itec-bridge probe <ip> [--port 4660] [--send <hex>] [--secs <n>]
```

- `--serial <port>` drives a local serial port directly (the bridge side of a virtual COM pair).
- `--listen <tcp-port>` serves a raw TCP endpoint on `127.0.0.1` instead.
- `--real` uses the full device transport; without it a stub is used (no device contact).
- The serial line settings (`--baud`/`--data`/`--parity`/`--stop`) are applied to the remote
  device; the local COM port's own baud is not significant.
- `probe` is a read-only diagnostic that sends optional bytes and prints the reply as hex.
- Set the environment variable `ITEC_DEBUG=1` to trace frames on the wire.

## Building

Builds with Rust 1.75 or newer. Continuous integration builds the CLI and GUI on Windows, Linux,
and macOS for every push; pushing a version tag (`vX.Y.Z`) produces a GitHub Release with archives
for all three platforms (see [`.github/workflows/release.yml`](.github/workflows/release.yml)).

## Repository layout

- `src/` — the Rust crate: `itec-bridge` (CLI) and `itec-bridge-gui` (GUI).
- `reverse-engineering/` — the protocol specification (`PROTOCOL.md`) and the driver
  decompilation it was derived from.

## Tested with

- Device: i-tec LAN2RS232 / ESTI E1868, firmware `V.100.067`.
- Attached equipment: Unitronics Vision `V120-22-UA2` PLC, verified with Unitronics VisiLogic at
  57600 8N1.

## License

MIT. See [`LICENSE`](LICENSE).
