# ESTI E1868 "Network USB Server" — protocol notes (from static analysis)

Source: `NU_V1.25.iso` (Internet Archive, MD5 aad64b5acde4eeafde1bbe7bce5f30b0), extracted statically; nothing executed.
Payload driver/app files are under `itec-work/downloads/nu125/files/`.

## Software components (what each does)
| File | Role |
|---|---|
| `networking_usb_server.exe` | The "Peripheral Server" GUI. Uses `CMulticastSocket`, `CDevice`, `CPSM` (printer), serial-number handling. |
| `dcpdll.dll` | **Discovery + device management** = "DCP" protocol over a **custom multicast UDP socket** (`CMulticastSocket`, `DCPPACKETHEADER`, `DCPPACKETHEADER_ES2868B`). Has ReadFlash/WriteFlash/Lock/Unlock/ResetServer "ByBroadcast". `GetServerSocketPort`, `GetMulticastSocketElement`, `SendToMulticastPackage(buf,len,?,ip,ip)`. |
| `psmdll.dll` | Print-server / USB-printer job logic. |
| `genhc.sys` | **The USB-over-IP transport.** A *virtual USB host controller* (NTMPDriver / `\GLOBAL??\HCD%d`) that opens **TCP** (`\Device\Tcp`) to the server and presents the remote USB device locally (`USB\Vid_%04X&Pid_%04X`, `\Device\Generic_%08X`). Reads server addr from registry (`...\Services\Tcpip\Parameters`, `HostName`). This is the component that must be understood to talk to the device directly by IP. Legacy TDI kernel sockets. |
| `genbus.sys` | Bus enumerator (`root\est_bus`, "EST_Bus.sys", "USB Server Bus Enumerator"). Surfaces discovered servers as a PnP bus. |
| `nus_bus.sys` | Newer bus enumerator variant (`root\NUS_Bus`, 2009-12-15). |
| `nuserver32/64.sys` (`nuserver.inf`) | Newer host-controller driver, binds `USB\ROOT_HUB_GENERIC&Rev_0201`. `genhc.inf` binds `Rev_0001`. |

## Which driver is this device?
- Firmware 100.067 ⇒ **E1868** (100.xxx line). `genhc.inf`/`genbus.inf` (Rev_0001) are the matching 2009 E1868 generation; `nuserver.inf` (Rev_0201) targets the newer E2868/E3868. Release notes repeatedly say "E1868 Driver: No Update", i.e. the E1868 driver was stable and bundled unchanged.

## Transport facts
- **Discovery:** custom DCP multicast (NOT the device's UPnP/SSDP, which exists only for Windows auto-discovery). Multicast = the reason it won't cross VLANs.
- **Data:** TCP port **4660 (0x1234)** on the server, spoken by `genhc.sys`. A raw HTTP line to 4660 returns 4 bytes `02 04 05 b4` + leftover web buffer, confirming a small binary framing in front.
- End result of a normal connect: device appears as **"Prolific USB-to-Serial Comm Port (COMx)"** — so the PL2303 is tunnelled as a USB device; baud/line settings go through normal PL2303 USB control transfers, not a text protocol.

## Two implementation roads
1. **Use the vendor driver, fix discovery only.** The driver already implements 4660 + USB tunnel + PL2303 correctly. Blocker = discovery (multicast) + a possible GUI "different subnet → cannot connect" restriction. Risk: drivers are 2009–2010 (XP/Vista/Win7 WHQL); loading them on **Windows 11** may require test-signing / may not work. Best when the target PC is older Windows, or a small VM/box can sit on VLAN 10 and re-share the COM port over TCP.
2. **Reimplement the 4660 USB-over-IP transport in Python (no vendor driver).** Pure IP, no multicast, no subnet check, Win11-safe. Cost: reverse `genhc.sys`'s TCP framing + USB enumeration + PL2303 control/bulk. Large effort. A strong accelerator would be the open-source Linux `nhci` driver (same vendor family) if its source can be found — it would reveal the framing even though it gates out E1868 by PID.

## User-provided build ("USB Server 2.zip" from the user's working PC)
- `GenHC.sys` is **byte-identical** (MD5 b63cb796f3fc7df6db5c0dd7e4a6f16d) to the ISO's — the transport driver I'm analyzing is exactly the user's. (GenBus.sys/DCPDLL.dll differ slightly in version but same family.)
- GUI "USB Server.exe": KVM build "0.0.4.9 Dec-1-2010". Has `CPSM::SetUpDifferentSegment`, `CPS::GetSegment`/`GetSubNet`, `CPSM::SetUpSubnet`.
- GUI user-facing strings include: "Device in different segment", "In different segment and error", "Occupy By IP :", "Subnet :", and the blocker **"Network segment of this server is not the same as local PC."**
  ⇒ The client *represents* different-segment servers and can target "By IP", but may refuse to *connect* to one on a different subnet, and in any case discovers only via multicast (won't cross VLANs unaided).

## Target-OS risk
- Drivers are 2009–2010 WHQL (XP/Vista/Win7). On Windows 11 they may fail to load without test-signing. Decisive for choosing the road.

## Open questions to resolve next
- DCP discovery UDP port + packet header layout (in `dcpdll.dll`) — needed for a cross-VLAN relay (road 1) or just to understand discovery.
- `genhc.sys` 4660 framing: the `02 04 xx xx` header and the USB-URB-over-TCP encoding (road 2).
- Whether the GUI has any manual "add server by IP" (would make road 1 trivial).
- Whether the 2010 signed drivers load on the user's target OS.


---

# GenHC.sys TCP-4660 USB-over-IP protocol (static analysis)

Target: `downloads/nu125/files/genhc.sys` (== user's `USB Server 2/Driver/GenHC.sys`, byte-identical).
AMD64 (PE32+ `machine=0x8664`), ImageBase `0x10000`, built "Oct 6 2009". **Debug build** — nearly every
function has a `DbgPrint`-style format string naming it, which is what makes this recoverable.

Method: Ghidra 12.2 could NOT run (it hard-requires JDK 25; only JDK 21 is installed — framework bytecode is
v25, so the launcher gate cannot be bypassed and no JDK was installed per offline/no-installer policy).
All findings below are from **capstone disassembly** of exact function boundaries parsed from the `.pdata`
RUNTIME_FUNCTION table (270 functions). Helper scripts: `scratchpad/disa2.py`. Nothing was executed; no host contact.

Confidence tags: **[C]** = read directly from code, **[I]** = inferred, **[?]** = open gap.

---

## 1. Transport layer  [C]

Legacy **TDI** kernel sockets (no WSK). Imports used: `ZwCreateFile`, `IoGetDeviceObjectPointer`,
`IoBuildDeviceIoControlRequest`, `IoAllocateMdl`, `MmProbeAndLockPages`, `IofCallDriver`.

- **`NetworkConnectionOpen(ctx, ip, port, connCtx)` @ `0x14adc`**
  1. `0x3cbb8` — "Initialize Transport Handles": opens `\Device\Tcp` (the TDI transport), creates a local
     TDI address object.
  2. `0x3d4f0` — "Create connection": creates a TDI connection endpoint and associates it.
  3. `0x3d080` — **TDI_Connect**. IP and port are converted to **network byte order** right before the call
     (`bswap r12d` on the IPv4 addr, `ror bp,8` on the 16-bit port). So the caller passes host-order values;
     the wire/connect uses a standard `TA_IP_ADDRESS`.
  4. Installs a `TDI_EVENT_DISCONNECT` handler (`TDI_ClientEventDisconnect` @ ~`0x????`, logged).
- **Server IP source**: registry `\Registry\Machine\System\CurrentControlSet\Services\Tcpip\Parameters`,
  value **`HostName`** [C — wide strings], plus per-device key via `IoOpenDeviceRegistryKey`. Port is a
  parameter (the literal 4660/0x1234 does **not** appear as a code immediate in genhc; it comes from
  config/genbus/GUI). Empirically confirmed = **4660 (0x1234)**.
- **Send path — `0x3d284`** `SendPacket(ctx, portIdx, tdiConnFileObj, buffer, sendLen, *out)`:
  builds an IRP with **`MajorFunction = 0x0F` (IRP_MJ_INTERNAL_DEVICE_CONTROL)**, **`MinorFunction = 0x07`
  (TDI_SEND)**, wraps `buffer` in an MDL (`IoAllocateMdl`+`MmProbeAndLockPages`), sets
  `Irp->MdlAddress`, `SendLength`, flags `0x180`, then `IoCallDriver` to `\Device\Tcp`. **Send length is read
  from `word[ctx+0x2000]`** (the server-provided session size, see §4), not from a per-packet field — i.e. the
  client emits fixed-size frames. [C for the IRP build; **[I]** for the length semantics]
- **Receive path — `0x24990`** `TDI_Receive_3(ctx, tdiConnFileObj, maxLen, buf, remaining, *recvd)`:
  issues TDI_RECEIVE; 0 bytes back ⇒ "connection disconnected".
- Per-port TDI connection file-objects live in an array at **`ctx + 0x1e70`, stride `0x30` (48 bytes), indexed
  by USB-port number** (same array used by both send and receive). `ctx = *(DeviceExtension+0x40)`.
- Pool tags: **`Est5`** (`0x35747345`) = receive buffer; **`EstS`** (`0x53747345`) = request descriptor
  (allocated from a lookaside list via `0x1bd38`).

---

## 2. RESPONSE framing (server → client)  [C — this is the solid part]

Parser: **`GetDataFromTDI` @ `0x204e0`** (called in a loop by the per-port Rx thread). It allocates a
`0x5b4`=**1460-byte** buffer (one Ethernet MSS), zeroes it, then:

1. **Reads exactly a 32-byte (`0x20`) header** in a loop until 32 bytes are in.
2. Parses the length, **reads `payloadLength` more bytes** into the same buffer right after the header
   (total target = `0x20 + payloadLength`).
3. Dispatches on the opcode byte.

### Response header — 32 bytes, byte-by-byte
| Offset | Size | Endian | Field | Evidence |
|---|---|---|---|---|
| 0x00 | 1 | - | type/class byte (observed `0x02`) | probe `02 04 05 b4` |
| 0x01 | 1 | - | subtype byte (observed `0x04`) | probe |
| 0x02–0x03 | 2 | ? | unknown (observed `05 b4`) — NOTE: this is *not* the length the parser uses | probe |
| **0x04–0x05** | 2 | **big-endian** | **payloadLength** (`movzx eax,[rsi+4]; ror ax,8`) | `0x205d5` [C] |
| 0x06 | 1 | - | status/command sub-byte (logged with Command) | `0x206a6` [C] |
| **0x07** | 1 | - | **opcode / Command** (dispatch) | `0x2063e` [C] |
| **0x08–0x09** | 2 | LE | **SeqNum** (echoes request seq) | `0x205b8` [C] |
| 0x0A | 1 | - | flags; **bit 0x80** selects completion handler | `0x20705` [C] |
| 0x0B–0x0F | 5 | - | unknown / reserved | - |
| **0x10** | 1 | - | **device/USB-port index** | `0x2068d` [C] |
| 0x11 | 1 | - | unknown | - |
| **0x12–0x13** | 2 | **big-endian** | value: handle, or for opcode 0x0A/0x1C the **session size** | `0x20689/0x206c7` [C] |
| 0x14–0x1F | 12 | - | unknown / reserved | - |
| 0x20.. | var | - | **payload** (`payloadLength` bytes) | [C] |

### Response opcode table (byte @ +0x07)  [C]
| Opcode(s) | Handling |
|---|---|
| `0x01 0x03 0x05 0x09 0x0F 0x17 0x29` | data-carrying completion. If `flags&0x80`: handler `0x1e658`; else `0x1ca80` (append/complete URB). |
| `0x0B 0x1D 0x1F` | control/ack: store status `byte@+0x06` into per-device slot `ctx+index*0x268+0x1010`, then `KeSetEvent` to wake the request thread. |
| `0x0A 0x1C` | session/frame-size ack: store `BE word@+0x12` into **`ctx+0x2000`** (used as the send frame length, §4). |

---

## 3. REQUEST framing (client → server)  [mixed — PARTIAL, see gaps]

Dispatcher: **`UrbFunctions` @ `0x1fa8c`**, switch on `URB->Function` (`word @ URB+2`, standard
`URB_FUNCTION_*` codes: 0x00 select-config, 0x01 select-interface, 0x02 abort-pipe, 0x08/0x0B get-descriptor,
0x09 bulk/interrupt, 0x13 class/vendor, …). Per-function builders: `0x16c48`(0), `0x1728c`(0x0B),
`0x170c8`(2), `0x18f58`(control/vendor), `0x17da0`, etc. All converge on serializer `0x3d284` (§1).

- **SeqNum** = 16-bit counter at **`ctx+0x210`**, `lock xadd` incremented per request, **value 0 is skipped**
  (`test r14w,r14w; je retry`). [C]
- Requests are built into the `EstS` **descriptor** (lookaside, ~`0x38` bytes + data).

### Control-transfer builder `SendUsbSetupPacketToDevice_2` @ `0x18f58`  [C for the field writes]
Writes into descriptor `rbx`:
| desc off | value |
|---|---|
| 0x00–0x0F | placeholder template `10 0f..01` copied from `.rdata@0x25c80` (overwritten/ignored) |
| 0x10 | magic **`"UNT$"`** = bytes `55 4E 54 24` (dword `0x24544E55`) |
| **0x1C** | **command code**: `0x33`=control-IN, `0x25`=control-OUT (wLength==0), `0x2D`=control-OUT w/ data |
| 0x20 | `0x01` |
| 0x21 / 0x22 | wValue low / high |
| 0x23 / 0x2A(low7) | wIndex low / high |
| 0x24–0x25 | total length = `wLength + 8` (12-bit) |
| 0x26 / 0x27 | wLength low / high |
| 0x28 / 0x29 | bmRequestType / bRequest |
| 0x2D,0x2E,0x2F | endpoint/direction flags |
| 0x30.. | the 8-byte USB SETUP packet (control), or data payload |

### Bulk / interrupt  [C from strings + handlers]
`BulkOrInterruptTransfer_*` / `BoI_Transfer_IN/OUT_Completion_2`. Large transfers are **segmented** and carry
a 32-bit **Offset** and 32-bit **PayloadLength** per frame (debug fmt `Offset_0x%08X, PayloadLength_0x%08X,
SeqNum_0x%04X` @ `0x2af1a`). IN pipes resubmit on NAK (`BoI_Transfer_IN_Completion_2: NAK. Resubmit`);
OUT has a NAK-timeout DPC.

---

## 4. Connection / handshake sequence  [I, grounded in C]

There is **no magic preamble on connect** — the client just TCP-connects to `serverIP:4660` and sets a TDI
disconnect handler. The application protocol then runs:

1. TCP connect to `IP:4660` (per USB port; one connection per claimed port, array at `ctx+0x1e70`).
2. Client issues USB enumeration requests (GET_DESCRIPTOR device/config/strings) as §3 control transfers,
   `SeqNum` incrementing from 1.
3. Server replies with 32-byte-header responses (§2), `SeqNum` echoed at +0x08.
4. A response with opcode **`0x0A`/`0x1C`** carries a **session/frame size** (BE word @+0x12) that the client
   stores at `ctx+0x2000` and thereafter uses as its **send frame length**. Treat obtaining this value as the
   effective handshake step. **[I]**
5. Periodic **keep-alive** (`SendKeepAlivePacketCallback`): on failure it completes the pending
   `IOCTL_EST_SERVER_STATUS_OUT` with `STATUS_CONNECTION_DISCONNECTED` and an `"UNT$"` unplug marker ⇒ Windows
   unplugs the device.

Driver↔genbus IOCTL interface (not wire): `IOCTL_EST_SERVER_STATUS_IN/OUT`, `IOCTL_EST_USB_DEVICE_CONNECT/DISCONNECT`.

---

## 5. PL2303 specifics  [C — by absence]

GenHC is a **generic** USB host-controller tunnel. It contains **no PL2303 / CDC / SET_LINE_CODING logic**.
Baud/line settings (`SET_LINE_CODING 0x20`, vendor writes) are issued by the *upper* Prolific function driver
as ordinary USB control transfers, which GenHC encapsulates transparently via §3 (command `0x33/0x25/0x2d`,
8-byte setup at desc+0x30). So a reimplementation must speak the §3 control-transfer encapsulation; the PL2303
requests themselves are standard and documented elsewhere.

---

## 6. Constant / opcode table
| Name | Value | Meaning |
|---|---|---|
| TCP port | `0x1234` / 4660 | server data port (empirical + task) |
| Pool tag Est5 | `0x35747345` | receive buffer |
| Pool tag EstS | `0x53747345` | request descriptor |
| Magic `UNT$` | `55 4E 54 24` | request-descriptor signature (desc+0x10); also unplug marker |
| Header length | `0x20` (32) | fixed response header |
| Rx buffer | `0x5b4` (1460) | max frame |
| TDI_SEND | major `0x0F`, minor `0x07` | IRP for transmit |
| Req cmd control-IN | `0x33` | desc+0x1C |
| Req cmd control-OUT (no data) | `0x25` | desc+0x1C |
| Req cmd control-OUT (w/ data) | `0x2D` | desc+0x1C |
| Resp data opcodes | `01 03 05 09 0F 17 29` | completion w/ payload |
| Resp ack opcodes | `0B 1D 1F` | status+event wake |
| Resp size opcodes | `0A 1C` | session size → ctx+0x2000 |

## 7. Key function addresses (VA, ImageBase 0x10000)
| VA | Name |
|---|---|
| 0x14adc | NetworkConnectionOpen |
| 0x3cbb8 | open \Device\Tcp / init transport handles |
| 0x3d4f0 | create TDI connection |
| 0x3d080 | TDI_Connect (IP+port → network order) |
| 0x3d284 | serializer + TDI_SEND |
| 0x24990 | TDI_Receive_3 |
| 0x204e0 | **GetDataFromTDI** (response parser) |
| 0x1fa8c | UrbFunctions (request dispatcher, SeqNum @ctx+0x210) |
| 0x18f58 | SendUsbSetupPacketToDevice_2 (control builder) |
| 0x17e54 | SendKeepAlivePacketCallback |
| 0x1bd38 | descriptor allocator (lookaside, EstS) |
| 0x1e658 / 0x1ca80 | response-with-data completion handlers |
| 0x121dc | DbgPrint logging stub (ecx=level, rdx=ctx, r8=fmt, r9+stack=args) |

---

## 8. Biggest remaining unknowns  [?]
1. **Exact REQUEST (client→server) wire-byte layout.** The response header (§2) is solidly decoded, but the
   request descriptor's `"UNT$"@0x10` + command@`0x1C` do **not** align with the response header offsets. Either
   (a) the request header is asymmetric to the response, or (b) `0x3d284` serialises the descriptor into a
   different on-wire order that wasn't fully traced (the MDL is built over the descriptor base, and the
   placeholder bytes at desc+0x00..0x0F are sent as-is, which is suspicious). **This is the #1 thing to confirm
   with a single Wireshark capture** of one real control transfer, or by fully tracing how `word[ctx+0x2000]`
   bytes map out of the descriptor.
2. Meaning of response bytes +0x02–0x03 (the observed `05 b4`) and the +0x06/+0x07 command split; whether
   PortAddr is 1 or 2 bytes on the wire.
3. `ctx+0x2000` role is inferred as negotiated frame/transfer size; could be max-transfer-size.
4. Endpoint/direction → request-command mapping beyond control (exact bulk IN/OUT opcodes).
5. Whether a specific first request is required before the server sends the `0x0A/0x1C` size ack.

**Recommendation:** the response path is reimplementable now; the request path needs one captured session (or a
targeted re-trace of `0x3d284`) to lock the byte order before coding the client transmit side.

> **UPDATE (2026-10-26): gap #1 resolved below in §9.** The byte order is now locked from decompilation —
> no capture needed. JDK 25 was obtained (Adoptium Temurin 25.0.5+8 portable zip) and Ghidra 12.2 ran
> headless successfully (302 functions decompiled to `itec-work/genhc_decomp.c`); its output agrees
> byte-for-byte with the capstone trace. The transmit path is now reimplementable.

---

## 9. Request (TX) wire format — resolved  [C unless tagged]

### 9.0 How the bytes reach the socket (resolves gap #1)  [C]
`SendUsbSetupPacketToDevice_2`/the bulk builders build a **fresh descriptor** (lookaside `EstS`, allocator
`0x1bd38`), **`memset` it to 0 for `word[ctx+0x2000]` bytes** (`0x251f0`, confirmed `FUN_000251f0(puVar11,0,uVar9)`),
then write the fields below. The serializer `0x3d284` is called as
`FUN_0003d284(ctx, deviceIdx, connFileObj, descriptor, sendLen = word[ctx+0x2000], &out)` and does
**`IoAllocateMdl(rcx = descriptor_base, edx = sendLen)` → `MmProbeAndLockPages` → TDI_SEND**. **The MDL covers the
descriptor from offset 0, and `SendLength = word[ctx+0x2000]`.** Therefore:

> **The on-wire request bytes ARE the descriptor buffer verbatim, offset 0x00 .. (sessionSize-1). There is NO
> reordering and NO separate header. Every frame is padded with zeros out to the latched session/frame size
> `word[ctx+0x2000]`.** (This is the asymmetry hinted at in §8: the request framing is simply a different,
> fixed-size-frame layout from the 32-byte response header — both confirmed, they need not match.)

The first 16 bytes (0x00–0x0F) are a `.rdata` template (RVA `0x25c80`, file off `0x24680`) copied via `movdqu`:
**`10 0f 0e 0d 0c 0b 0a 09 08 07 06 05 04 03 02 01`** — a descending-counter **placeholder** the client always
emits; none of these 16 bytes is recomputed per request. **[C — bytes read from the image]**, **[I]** that the
server ignores them (they are a constant filler; the meaningful descriptor starts at 0x10 with `UNT$`).

### 9.1 Control transfer — full byte layout (desc = wire)  [C]
Fields written by `SendUsbSetupPacketToDevice_2` @ `0x18f58` (verified in both capstone and `genhc_decomp.c`
`FUN_00018f58`). `S[]` = the 8-byte USB SETUP packet (`S[0]`=bmRequestType … `S[6..7]`=wLength, little-endian).

| Wire off | Width | Endian | Field | Value / source | Conf |
|---|---|---|---|---|---|
| 0x00–0x0F | 16 | - | placeholder template | const `10 0f 0e …02 01` | C |
| 0x10–0x13 | 4 | - | **`UNT$` signature** | `55 4E 54 24` | C |
| 0x14 | 1 | - | following-length, **high nibble** (mirror of 0x25&0xf) | `(totalLen>>8)&0xf` | C |
| 0x15 | 1 | - | following-length, **low byte** (mirror of 0x24) | `totalLen&0xff` | C |
| 0x16 | 1 | - | **device / USB-port index** | `deviceObject[0x24]` | C |
| 0x17 | 1 | - | transfer-type/command for non-control; **0x00 for control** | 0 here | C |
| 0x18–0x19 | 2 | **LE** | **SeqNum** | parent-desc[0x10] (the 16-bit counter `ctx+0x210`, 0 skipped) | C |
| 0x1A–0x1B | 2 | - | reserved | 0 (zeroed) | C |
| 0x1C | 1 | - | **command code** | `0x33` ctrl-IN / `0x25` ctrl-OUT(wLen=0) / `0x2D` ctrl-OUT(wLen>0) | C |
| 0x1D–0x1F | 3 | - | reserved | 0 | C |
| 0x20 | 1 | - | const | `0x01` | C |
| 0x21 | 1 | - | wValue low | `S[2]` | C |
| 0x22 | 1 | - | wValue high | `S[3]` | C |
| 0x23 | 1 | - | wIndex low | `S[4]` | C |
| 0x24 | 1 | - | following-length low byte | IN: `8`; OUT: `(wLength+8)&0xff` | C |
| 0x25 | 1 | - | following-length high nibble (low nibble of byte) | IN: `0`; OUT: `((wLength+8)>>8)&0xf` | C |
| 0x26 | 1 | - | wLength low | `S[6]` (IN clamped to ≤ sessionSize) | C |
| 0x27 | 1 | - | wLength high | `S[7]` | C |
| 0x28 | 1 | - | **bmRequestType** | `S[0]` | C |
| 0x29 | 1 | - | **bRequest** | `S[1]` | C |
| 0x2A | 1 | - | wIndex high (bit7 forced 0) | `S[5] & 0x7f` | C |
| 0x2B–0x2C | 2 | - | reserved | 0 | C |
| 0x2D | 1 | - | endpoint nibble `|` (deviceIndex-1)<<4 | low nibble 0 for EP0 | C |
| 0x2E | 1 | - | deviceIndex & 0xf | | C |
| 0x2F | 1 | - | dir/flags | `(prev & 0xcb) | 0x08` ⇒ `0x08` | C |
| 0x30–0x37 | 8 | - | **8-byte USB SETUP packet `S[]`** | copied verbatim (GET_DESCRIPTOR path `puVar11[6]=*setup`) | C |
| 0x38.. | var | - | **OUT data payload** (cmd 0x2D only) | `wLength` bytes from URB TransferBuffer | C |
| … | - | - | zero padding to `word[ctx+0x2000]` | | C |

Notes: the "following-length" (12-bit) appears **twice** — at 0x14/0x15 and at 0x24/0x25 — both encode the
number of meaningful bytes after the setup header region: `8` for control-IN (setup only), `wLength+8` for
control-OUT with data. wValue/wIndex/wLength are additionally broken out at 0x21–0x2A *and* the whole 8-byte
setup is duplicated at 0x30. For **non-descriptor** control (URB func ≠ 8/0x32) the setup is copied to 0x30 for
`length` bytes instead of a fixed 8.

### 9.2 Example — GET_DESCRIPTOR(device), control-IN  [C-derived]
URB_FUNCTION_GET_DESCRIPTOR_FROM_DEVICE, standard SETUP = `80 06 00 01 00 00 12 00`
(bmRequestType=0x80 IN, bRequest=0x06 GET_DESCRIPTOR, wValue=0x0100 type=DEVICE/index 0, wIndex=0, wLength=18).
Assume **deviceIndex = 1** and **SeqNum = 0x0001**. The frame emitted (before zero-padding to `word[ctx+0x2000]`):

```
off  0x00: 10 0f 0e 0d 0c 0b 0a 09 08 07 06 05 04 03 02 01   ; placeholder template
off  0x10: 55 4e 54 24                                        ; "UNT$"
off  0x14: 00 08                                              ; len hi-nibble / len lo-byte  = 0x008
off  0x16: 01                                                 ; deviceIndex = 1
off  0x17: 00                                                 ; type=0 (control)
off  0x18: 01 00                                              ; SeqNum = 1 (LE)
off  0x1a: 00 00                                              ; reserved
off  0x1c: 33                                                 ; command = control-IN
off  0x1d: 00 00 00                                           ; reserved
off  0x20: 01                                                 ; const 0x01
off  0x21: 00 01 00                                           ; wValueL=00 wValueH=01 wIndexL=00
off  0x24: 08 00                                              ; following-len lo=8 / hi-nibble=0
off  0x26: 12 00                                              ; wLength = 0x0012 (LE)
off  0x28: 80 06                                              ; bmRequestType=0x80 bRequest=0x06
off  0x2a: 00 00 00                                           ; wIndexH=0, reserved
off  0x2d: 00 01 08                                           ; EP/addr nibbles (idx1), dir flags=0x08
off  0x30: 80 06 00 01 00 00 12 00                            ; 8-byte USB SETUP (duplicated)
off  0x38: 00 00 … 00                                         ; zero pad to sessionSize
```

Linear hex (0x00–0x37): `10 0F 0E 0D 0C 0B 0A 09 08 07 06 05 04 03 02 01 55 4E 54 24 00 08 01 00 01 00 00 00
33 00 00 00 01 00 01 00 08 00 12 00 80 06 00 00 00 00 01 08 80 06 00 01 00 00 12 00`, then zero-padded to the
latched frame size. The server reply arrives as a §2 32-byte-header response with the same SeqNum at resp+0x08.

### 9.3 Bulk / interrupt transfer  [C for the field map]
Dispatched from `UrbFunctions` (URB func 9) → `0x170c8`, which forks on the endpoint-descriptor direction bit
(`bmEndpointAddress & 0x80`): **IN → `0x192c0`, OUT → `0x19630`**. Both build the **same descriptor base**
(`UNT$`@0x10, deviceIndex@0x16, SeqNum@0x18 LE, 12-bit length @0x14/0x15 and mirror @0x24/0x25, data @0x30),
sent through the identical `0x3d284` path (MDL over descriptor base, `SendLength = word[ctx+0x2000]`). Differences
from control:

| Wire off | Field | Bulk/interrupt value | Conf |
|---|---|---|---|
| 0x17 | **transfer-type/command** | `0x02` = OUT; `0x04` = bulk-IN; `0x08` = interrupt-IN | C |
| 0x1C | command byte | **0x00** (unused for bulk; the 0x17 byte carries the type) | C |
| 0x14/0x15, 0x24/0x25 | per-frame payload length (12-bit) | bytes carried in THIS frame (clamped to endpoint `wMaxPacketSize`-derived chunk / sessionSize) | C |
| 0x1E | **segment count** (total frames for the transfer) | `ceil(totalLen / maxChunk)` | C |
| 0x1F | **current segment index** (0-based) | per-frame, OUT builder loops it | C |
| 0x30.. | data payload | `length` bytes from URB TransferBuffer at running offset | C |
| 0x22,0x23,0x28,0x29,0x2A,0x2B | interrupt-IN extras (`0x28`=0x04,`0x29`=0xF8, interval@0x22) / addr flag @0x2A bit7,@0x2B | set only on some paths | C |

Large transfers are split into `0x1E` segments; the running byte **Offset** into the URB buffer is tracked
host-side (`dword[urb+0x80]`, debug fmt `Offset_0x%08X, PayloadLength_0x%08X, SeqNum_0x%04X` @ `0x2af1a`), while
the **per-frame length** on the wire is the 12-bit 0x14/0x15 (+0x24/0x25) field, not a separate 32-bit field in
the sent descriptor. IN resubmits on NAK; OUT has a NAK-timeout DPC. **[I]** that the server reassembles using
`0x1E`/`0x1F` + SeqNum.

### 9.4 Residual gaps  [?]
1. Semantics of the 16-byte placeholder (0x00–0x0F): confirmed emitted as the constant counter, **[I]** that the
   server ignores it. A single capture would confirm whether the server echoes/validates it.
2. Exact meaning of the 0x2D/0x2E/0x2F endpoint/address nibble encoding for multi-endpoint devices (EP0 case is
   trivially 0x00/idx/0x08; non-zero endpoints set the low nibble of 0x2D from the pipe handle — not fully
   enumerated here).
3. The `ctx+0x2000` session/frame size is still **[I]** as "fixed send frame length"; it governs both the
   `memset` width and `SendLength`, so a wrong value truncates or over-pads every frame. Its negotiated value
   comes from the §2 opcode `0x0A/0x1C` response (BE word @resp+0x12).
4. Whether interrupt-OUT uses a distinct 0x17 code (only OUT=0x02 and the two IN codes were observed).

---

## 10. Session lifecycle & endpoints  [new — RX format corrected, lifecycle traced from genhc_decomp.c]

> **Correction to §2:** the real reply to a proper request is a `"UNT$"`-framed
> descriptor (effectively the request descriptor with its 16-byte placeholder
> prefix stripped, so every request field shifts **down by 0x10**), **not** the
> `02 04 05 b4 …` shape (that only appeared because the server was fed a raw HTTP
> line). Ground truth: `raw/getdesc_response.bin` (58 B), reply to
> GET_DESCRIPTOR(device) seq=1.

### 10.0 Real response layout (confirmed vs `GetDataFromTDI` @0x204e0 + oracle)  [C]
| Off | Field | Oracle value |
|---|---|---|
| 0x00–0x03 | **`"UNT$"` magic** (validated: `*param_2 != 0x24544e55` in `FUN_0001ca80`) | `55 4e 54 24` |
| 0x04–0x05 | **payloadLength** BE (`movzx eax,[rsi+4]; ror ax,8`; total frame = `0x20+len`) | `00 1a` = 26 = 8 setup + 18 data |
| 0x06 | status sub-byte | `01` |
| 0x07 | **dispatch opcode** (GenHC switches on THIS byte; `01/03/05/09/0f/17/29`=data) | `01` → data completion |
| 0x08–0x09 | **SeqNum** LE (`*(u16*)(param_2+8)`) | `01 00` = 1 |
| 0x0C | **echoed request command** | `33` = ctrl-IN |
| 0x10 | device/USB-port index | `08` |
| 0x12–0x13 | BE value: handle, or session size for 0x0A/0x1C | — |
| 0x20–0x27 | **echoed 8-byte SETUP** | `80 06 00 01 00 00 12 00` |
| **0x28..** | **control-transfer DATA payload** (= `payloadLength − 8` bytes) | 18-byte PL2303 device descriptor (`idVendor 067b`, `idProduct 2303`) |

The parser reads a fixed **32-byte header, then `len@0x04` BE more bytes** (the
echoed SETUP + DATA region). The USB data the caller wants begins at **0x28**
(`DATA_OFFSET = HEADER_LEN + 8`). Implemented in `src/transport/esti4660.rs`
(`ResponseHeader`/`read_frame`/`Frame::data`/`Dispatcher`), oracle-tested.

### 10.1 Post-connect sequence (keep the link alive)  [C unless tagged]
Driven by the device-connect orchestration (`FUN_0001f788` → `FUN_0002028c` →
`NetworkConnectionOpen`@0x14adc → `FUN_00014db0`):

1. **TCP connect** to `IP:4660` (`FUN_00014adc`). No connect-time preamble. [C]
2. **Start the per-port Rx worker** (`FUN_0002028c` → `FUN_0002010c` →
   `GetDataFromTDI`@0x204e0). [C]
3. **Send the session-open / claim message** — `FUN_00014db0(ctx, portIdx, 0x0A)`:
   a **0x74 (116)-byte** `"UNT$"` frame with **type `0x0A` @0x17**, deviceIndex
   @0x16, a fresh SeqNum @0x18 LE, the 16-byte placeholder @0x00, and a payload
   block copied from `.data` (`DAT_00037830`, `DAT_0003782c` bytes) at ~0x30.
   Sent through the normal serializer `0x3d284` with `SendLength=0x74`; the thread
   then **blocks on `KeWaitForSingleObject`** for the server's reply. **This is the
   step our live experiment skipped.** [C]
4. **Server replies with the `0x0A`/`0x1C` session-size ack** → `GetDataFromTDI`
   stores BE word@resp+0x12 into **`ctx+0x2000`** and `KeSetEvent`s the waiter. [C]
5. **Then** USB enumeration (GET_DESCRIPTOR device/config/strings, SET_LINE_CODING,
   …) runs as §9 control transfers. [I — grounded in the call order]
6. **Keep-alive** — `FUN_00017e54` (queued via `IoQueueWorkItem`) periodically
   sends a small (~0x20-byte) `"UNT$"` frame with **type `0x12` @0x17**, deviceIndex
   @0x16, fresh SeqNum @0x18, padded to the frame size. Interval seeded from the
   `0x3c` (=60) value stored at `ctx+index*0x268+0x1024`. On failure/timeout it
   emits the `"UNT$"` **unplug marker** (`word@+0x02 = 0x200`, status `0xC000020C`)
   ⇒ Windows unplugs the device. [C]

### 10.2 Frame-size handling (`ctx+0x2000`)  [C]
- **Initialized to `0x5b4` (1460)** at device creation (`*(u16*)(ctx+0x400) = 0x5b4`;
  `ctx` is a `longlong*`, so `+0x400` = byte `0x2000`) — same as the 1460-byte Rx
  buffer. So the send-frame size is valid from the first request; the client does
  **not** have to wait for the `0x0A/0x1C` ack to send.
- Every send: descriptor `memset` to 0 for `word[ctx+0x2000]` bytes, fields
  written, MDL covers `[base, base+size)` → **every frame is zero-padded to the
  frame size** (1460 by default).
- The `0x0A/0x1C` response **renegotiates** it (overwrites `ctx+0x2000`).
- Usable per-frame data = `word[ctx+0x2000] − 0x30` (the 0x30-byte request header),
  seen in the bulk chunking math (`(ctx+0x2000 − 0x30)/wMaxPacketSize`).

### 10.3 Why the server dropped after one transfer  [I — strongly grounded]
The client never did step 3 (the `0x0A` open/claim), so from the server's view the
session was never opened; it answered the single opportunistic control request and
tore the connection down. Contributing: our frame was **not padded to 1460**, and
**no `0x12` keep-alive** was ever sent. The fix for live bring-up: after TCP
connect, (a) send the `0x0A` claim frame and wait for the `0x0A/0x1C` size ack,
(b) pad every request out to `word[ctx+0x2000]` (start 1460), (c) run the `0x12`
keep-alive on the ~60-unit interval.

### 10.4 Bulk endpoint map + nibble encoding  [C for the encoder; PL2303 std for addresses]
PL2303 (standard HX/TA) endpoints — confirm from the device's own config
descriptor when live:
| Endpoint | bEndpointAddress | Use |
|---|---|---|
| Interrupt-IN | **0x81** (EP1) | modem/line status |
| **Bulk-OUT** | **0x02** (EP2) | serial TX (host→device) |
| **Bulk-IN** | **0x83** (EP3) | serial RX (device→host) |

Descriptor nibble encoding — the generic bulk/interrupt pipe serializer
`FUN_0001b110` @0x1b110 writes (verified in `genhc_decomp.c`): [C]
| Wire off | Field | Rule |
|---|---|---|
| 0x17 | transfer-type/command | `0x02`=bulk-OUT, `0x04`=bulk-IN, `0x08`=interrupt-IN |
| **0x2E** | **endpoint + device** | **high nibble = endpoint number (`bEndpointAddress & 0x0F`)**; low nibble = `deviceIndex & 0x0F`. (Builders read `EP = byte[0x2E] >> 4`.) |
| 0x2D | maxpkt-hi + port | high nibble = `(deviceIndex−1) << 4`; low nibble = `(wMaxPacketSize >> 8) & 0x7` |
| 0x2C | wMaxPacketSize low byte | |
| 0x2F | dir/type flags | bit `0x04` = IN (clear for OUT); bits 4–5 = `(bmAttributes & 3) << 4` → bulk = `0x20` |
| 0x16 | deviceIndex | |
| 0x1E / 0x1F | segment count / current index | |

So for `build_bulk_request` (deviceIndex=1, wMaxPacketSize=0x40):
- **Bulk-OUT (EP2):** `0x17=0x02`, `0x2E=0x21`, `0x2F=0x20`, `0x2D=0x00`, `0x2C=0x40`.
- **Bulk-IN (EP3):**  `0x17=0x04`, `0x2E=0x31`, `0x2F=0x24`, `0x2D=0x00`, `0x2C=0x40`.

The current `build_bulk_request` sets only `0x17` (and leaves `0x2C–0x2F` zero); to
target the right pipe it must also set **`0x2E` (EP nibble)** and **`0x2F`
(dir/type)** as above. [I — to implement on the TX side]

### 10.5 Residual unknowns to confirm live  [?]
1. Exact bytes of the 116-byte `0x0A` claim payload (`DAT_00037830`,
   `DAT_0003782c` long) — one capture of the first client→server frame confirms it.
2. Keep-alive period units (`0x3c=60`; s / ds?) and whether the server *requires*
   it or merely benefits.
3. Whether the `0x0A/0x1C` size ack is mandatory before enumeration, or the default
   1460 is enough (the driver waits for it; a minimal client may proceed on 1460).
4. PL2303 endpoint addresses above are the standard layout — read them from the
   device's returned CONFIGURATION descriptor rather than hard-coding, in case this
   unit is a PL2303 variant with different EP numbers.
