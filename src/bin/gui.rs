//! itec-bridge-gui — a minimal cross-platform desktop GUI around the
//! `itec-bridge` library, so a non-technical user can run the bridge without the
//! command line.
//!
//! Pure-Rust UI (eframe/egui, no system webview). The bridge runs on a
//! background thread with its own tokio runtime; the egui UI thread never
//! blocks. Start/Stop drive the library's programmatic shutdown signal
//! ([`server::run_with_shutdown`] / [`server::run_serial_with_shutdown`]); the
//! bridge's log lines are captured through the library's log sink
//! ([`itec_bridge::logging`]) and shown live. Settings persist to a JSON file in
//! the OS config dir.

use std::fmt;
use std::fs;
use std::net::{SocketAddr, ToSocketAddrs};
use std::path::PathBuf;
use std::sync::mpsc::{self, Receiver, Sender};
use std::thread::{self, JoinHandle};
use std::time::Duration;

use eframe::egui;
use serde::{Deserialize, Serialize};
use tokio::sync::watch;

use itec_bridge::server;
use itec_bridge::transport::{
    DataBits, Esti4660Transport, LineCoding, Parity, StopBits, StubTransport, Transport,
    TransportError,
};

/// How the local endpoint is exposed: a local serial (com0com) port, or a local
/// TCP listener a COM-port shim attaches to.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
enum Mode {
    SerialCom,
    TcpListen,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
enum ParityChoice {
    None,
    Odd,
    Even,
    Mark,
    Space,
}

impl fmt::Display for ParityChoice {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let s = match self {
            ParityChoice::None => "none",
            ParityChoice::Odd => "odd",
            ParityChoice::Even => "even",
            ParityChoice::Mark => "mark",
            ParityChoice::Space => "space",
        };
        f.write_str(s)
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
enum StopChoice {
    One,
    OnePointFive,
    Two,
}

impl fmt::Display for StopChoice {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let s = match self {
            StopChoice::One => "1",
            StopChoice::OnePointFive => "1.5",
            StopChoice::Two => "2",
        };
        f.write_str(s)
    }
}

/// User-editable, persisted configuration.
#[derive(Debug, Clone, Serialize, Deserialize)]
struct Settings {
    device_ip: String,
    device_port: u16,
    mode: Mode,
    serial_port: String,
    tcp_port: u16,
    baud: u32,
    data_bits: u8,
    parity: ParityChoice,
    stop_bits: StopChoice,
    /// Use the real 4660 transport (connect + claim + keep-alive). Uncheck to
    /// run against the no-device StubTransport for a plumbing test.
    use_real: bool,
}

impl Default for Settings {
    fn default() -> Self {
        Settings {
            device_ip: "192.168.10.10".to_string(),
            device_port: 4660,
            mode: Mode::SerialCom,
            serial_port: "COM21".to_string(),
            tcp_port: 5660,
            baud: 57600,
            data_bits: 8,
            parity: ParityChoice::None,
            stop_bits: StopChoice::One,
            use_real: true,
        }
    }
}

impl Settings {
    /// Translate the UI choices into the library's [`LineCoding`], validating the
    /// data-bits field (mirrors the CLI's mapping).
    fn line_coding(&self) -> Result<LineCoding, String> {
        let data_bits = match self.data_bits {
            5 => DataBits::Five,
            6 => DataBits::Six,
            7 => DataBits::Seven,
            8 => DataBits::Eight,
            other => return Err(format!("invalid data bits {other} (expected 5..=8)")),
        };
        Ok(LineCoding {
            baud: self.baud,
            data_bits,
            parity: match self.parity {
                ParityChoice::None => Parity::None,
                ParityChoice::Odd => Parity::Odd,
                ParityChoice::Even => Parity::Even,
                ParityChoice::Mark => Parity::Mark,
                ParityChoice::Space => Parity::Space,
            },
            stop_bits: match self.stop_bits {
                StopChoice::One => StopBits::One,
                StopChoice::OnePointFive => StopBits::OnePointFive,
                StopChoice::Two => StopBits::Two,
            },
        })
    }
}

/// Path of the persisted settings file in the OS config dir, if resolvable.
fn config_path() -> Option<PathBuf> {
    directories::ProjectDirs::from("", "", "itec-bridge")
        .map(|d| d.config_dir().join("gui-settings.json"))
}

/// Load settings from disk, falling back to defaults on any error.
fn load_settings() -> Settings {
    if let Some(path) = config_path() {
        if let Ok(text) = fs::read_to_string(path) {
            match serde_json::from_str::<Settings>(&text) {
                Ok(s) => return s,
                Err(_) => { /* corrupt/old file: fall back to defaults */ }
            }
        }
    }
    Settings::default()
}

/// Persist settings to disk. All IO is best-effort; failures are returned so the
/// caller can surface them in the log, never panicking.
fn save_settings(settings: &Settings) -> Result<(), String> {
    let path = config_path().ok_or_else(|| "could not resolve a config directory".to_string())?;
    if let Some(parent) = path.parent() {
        fs::create_dir_all(parent).map_err(|e| format!("create {}: {e}", parent.display()))?;
    }
    let text = serde_json::to_string_pretty(settings).map_err(|e| e.to_string())?;
    fs::write(&path, text).map_err(|e| format!("write {}: {e}", path.display()))
}

/// Lifecycle events the bridge thread reports back to the UI.
enum Event {
    /// Transport established; the bridge is now serving.
    Running,
    /// The bridge stopped cleanly (shutdown or client EOF).
    Stopped,
    /// The bridge failed; carries the error text.
    Error(String),
}

/// Handle to an in-progress bridge run.
struct Control {
    shutdown: watch::Sender<bool>,
    events: Receiver<Event>,
    handle: Option<JoinHandle<()>>,
}

/// Resolve the transport, then run the selected endpoint until shutdown. Runs on
/// the bridge thread, inside its own tokio runtime.
async fn run_bridge(settings: Settings, shutdown: watch::Receiver<bool>, events: Sender<Event>) {
    let coding = match settings.line_coding() {
        Ok(c) => c,
        Err(e) => {
            let _ = events.send(Event::Error(e));
            return;
        }
    };

    let device: SocketAddr = match format!("{}:{}", settings.device_ip, settings.device_port)
        .to_socket_addrs()
        .ok()
        .and_then(|mut it| it.next())
    {
        Some(a) => a,
        None => {
            let _ = events.send(Event::Error(format!(
                "could not resolve device address {}:{}",
                settings.device_ip, settings.device_port
            )));
            return;
        }
    };

    let transport: Box<dyn Transport> = if settings.use_real {
        itec_bridge::log_line!("connecting to device {device} (real 4660 transport) ...");
        match Esti4660Transport::connect(device).await {
            Ok(t) => {
                itec_bridge::log_line!("connected; pl2303 open done");
                Box::new(t)
            }
            Err(e) => {
                let _ = events.send(Event::Error(format!("connect failed: {e}")));
                return;
            }
        }
    } else {
        itec_bridge::log_line!("using StubTransport (real device disabled)");
        Box::new(StubTransport::new())
    };

    let _ = events.send(Event::Running);

    let result: Result<(), TransportError> = match settings.mode {
        Mode::SerialCom => {
            server::run_serial_with_shutdown(
                settings.serial_port.clone(),
                coding.baud,
                transport,
                coding,
                shutdown,
            )
            .await
        }
        Mode::TcpListen => {
            let listen: SocketAddr = ([127, 0, 0, 1], settings.tcp_port).into();
            server::run_with_shutdown(listen, transport, coding, shutdown).await
        }
    };

    match result {
        Ok(()) => {
            let _ = events.send(Event::Stopped);
        }
        Err(e) => {
            let _ = events.send(Event::Error(e.to_string()));
        }
    }
}

/// Cap on retained log lines, so a long-running session does not grow unbounded.
const LOG_CAP: usize = 5000;

struct BridgeApp {
    settings: Settings,
    status: String,
    logs: Vec<String>,
    /// Receiver for library log lines (sink installed in [`BridgeApp::new`]).
    log_rx: Receiver<String>,
    /// Present while a bridge run is active (started, not yet stopped).
    control: Option<Control>,
    /// Set true after a Stop click, cleared when the run confirms it stopped.
    stopping: bool,
}

impl BridgeApp {
    fn new(_cc: &eframe::CreationContext<'_>) -> Self {
        // Route the library's log lines to us for the lifetime of the app.
        let (log_tx, log_rx) = mpsc::channel::<String>();
        itec_bridge::logging::set_sink(log_tx);

        BridgeApp {
            settings: load_settings(),
            status: "stopped".to_string(),
            logs: Vec::new(),
            log_rx,
            control: None,
            stopping: false,
        }
    }

    fn running(&self) -> bool {
        self.control.is_some()
    }

    /// A one-line description of the active endpoint for the status line.
    fn endpoint_desc(&self) -> String {
        match self.settings.mode {
            Mode::SerialCom => format!(
                "{} \u{2194} {}",
                self.settings.serial_port, self.settings.device_ip
            ),
            Mode::TcpListen => format!(
                "tcp :{} \u{2194} {}",
                self.settings.tcp_port, self.settings.device_ip
            ),
        }
    }

    fn start(&mut self) {
        if self.running() {
            return;
        }
        // Persist the settings we are about to run with.
        if let Err(e) = save_settings(&self.settings) {
            self.push_log(format!("warning: could not save settings: {e}"));
        }

        let (shutdown_tx, shutdown_rx) = watch::channel(false);
        let (event_tx, event_rx) = mpsc::channel::<Event>();
        let settings = self.settings.clone();

        let handle = thread::Builder::new()
            .name("itec-bridge".to_string())
            .spawn(move || match tokio::runtime::Runtime::new() {
                Ok(rt) => rt.block_on(run_bridge(settings, shutdown_rx, event_tx)),
                Err(e) => {
                    let _ = event_tx.send(Event::Error(format!("tokio runtime: {e}")));
                }
            });

        match handle {
            Ok(handle) => {
                self.control = Some(Control {
                    shutdown: shutdown_tx,
                    events: event_rx,
                    handle: Some(handle),
                });
                self.stopping = false;
                self.status = "connecting\u{2026}".to_string();
            }
            Err(e) => {
                self.push_log(format!("error: could not start bridge thread: {e}"));
                self.status = format!("error: {e}");
            }
        }
    }

    fn stop(&mut self) {
        if let Some(control) = &self.control {
            let _ = control.shutdown.send(true);
            self.stopping = true;
            self.status = "stopping\u{2026}".to_string();
        }
    }

    fn push_log(&mut self, line: String) {
        self.logs.push(line);
        if self.logs.len() > LOG_CAP {
            let overflow = self.logs.len() - LOG_CAP;
            self.logs.drain(0..overflow);
        }
    }

    /// Drain the log channel and any lifecycle events from the bridge thread.
    fn pump_channels(&mut self) {
        while let Ok(line) = self.log_rx.try_recv() {
            self.push_log(line);
        }

        // Collect events first to avoid holding a borrow of `self.control`.
        let mut events = Vec::new();
        if let Some(control) = &self.control {
            while let Ok(ev) = control.events.try_recv() {
                events.push(ev);
            }
        }
        for ev in events {
            match ev {
                Event::Running => {
                    if !self.stopping {
                        self.status = format!("running: {}", self.endpoint_desc());
                    }
                }
                Event::Stopped => self.finish_run("stopped".to_string()),
                Event::Error(e) => self.finish_run(format!("error: {e}")),
            }
        }
    }

    fn finish_run(&mut self, status: String) {
        if let Some(mut control) = self.control.take() {
            if let Some(handle) = control.handle.take() {
                let _ = handle.join();
            }
        }
        self.stopping = false;
        self.status = status;
    }
}

impl eframe::App for BridgeApp {
    fn update(&mut self, ctx: &egui::Context, _frame: &mut eframe::Frame) {
        self.pump_channels();

        egui::CentralPanel::default().show(ctx, |ui| {
            ui.heading("i-tec LAN2RS232 bridge");
            ui.add_space(4.0);

            let editable = !self.running();

            egui::Grid::new("config")
                .num_columns(2)
                .spacing([12.0, 6.0])
                .show(ui, |ui| {
                    ui.label("Device IP");
                    ui.add_enabled(
                        editable,
                        egui::TextEdit::singleline(&mut self.settings.device_ip),
                    );
                    ui.end_row();

                    ui.label("Device port");
                    ui.add_enabled(
                        editable,
                        egui::DragValue::new(&mut self.settings.device_port).speed(1.0),
                    );
                    ui.end_row();

                    ui.label("Mode");
                    ui.add_enabled_ui(editable, |ui| {
                        egui::ComboBox::from_id_source("mode")
                            .selected_text(match self.settings.mode {
                                Mode::SerialCom => "Serial COM",
                                Mode::TcpListen => "TCP listen",
                            })
                            .show_ui(ui, |ui| {
                                ui.selectable_value(
                                    &mut self.settings.mode,
                                    Mode::SerialCom,
                                    "Serial COM",
                                );
                                ui.selectable_value(
                                    &mut self.settings.mode,
                                    Mode::TcpListen,
                                    "TCP listen",
                                );
                            });
                    });
                    ui.end_row();

                    match self.settings.mode {
                        Mode::SerialCom => {
                            ui.label("Serial port");
                            ui.add_enabled(
                                editable,
                                egui::TextEdit::singleline(&mut self.settings.serial_port),
                            );
                        }
                        Mode::TcpListen => {
                            ui.label("TCP listen port");
                            ui.add_enabled(
                                editable,
                                egui::DragValue::new(&mut self.settings.tcp_port).speed(1.0),
                            );
                        }
                    }
                    ui.end_row();

                    ui.label("Baud");
                    ui.add_enabled_ui(editable, |ui| {
                        egui::ComboBox::from_id_source("baud")
                            .selected_text(self.settings.baud.to_string())
                            .show_ui(ui, |ui| {
                                for b in [1200u32, 2400, 4800, 9600, 19200, 38400, 57600, 115200] {
                                    ui.selectable_value(&mut self.settings.baud, b, b.to_string());
                                }
                            });
                    });
                    ui.end_row();

                    ui.label("Data bits");
                    ui.add_enabled_ui(editable, |ui| {
                        egui::ComboBox::from_id_source("data_bits")
                            .selected_text(self.settings.data_bits.to_string())
                            .show_ui(ui, |ui| {
                                for d in [5u8, 6, 7, 8] {
                                    ui.selectable_value(
                                        &mut self.settings.data_bits,
                                        d,
                                        d.to_string(),
                                    );
                                }
                            });
                    });
                    ui.end_row();

                    ui.label("Parity");
                    ui.add_enabled_ui(editable, |ui| {
                        egui::ComboBox::from_id_source("parity")
                            .selected_text(self.settings.parity.to_string())
                            .show_ui(ui, |ui| {
                                for p in [
                                    ParityChoice::None,
                                    ParityChoice::Odd,
                                    ParityChoice::Even,
                                    ParityChoice::Mark,
                                    ParityChoice::Space,
                                ] {
                                    ui.selectable_value(
                                        &mut self.settings.parity,
                                        p,
                                        p.to_string(),
                                    );
                                }
                            });
                    });
                    ui.end_row();

                    ui.label("Stop bits");
                    ui.add_enabled_ui(editable, |ui| {
                        egui::ComboBox::from_id_source("stop_bits")
                            .selected_text(self.settings.stop_bits.to_string())
                            .show_ui(ui, |ui| {
                                for s in
                                    [StopChoice::One, StopChoice::OnePointFive, StopChoice::Two]
                                {
                                    ui.selectable_value(
                                        &mut self.settings.stop_bits,
                                        s,
                                        s.to_string(),
                                    );
                                }
                            });
                    });
                    ui.end_row();

                    ui.label("Real device");
                    ui.add_enabled(
                        editable,
                        egui::Checkbox::new(&mut self.settings.use_real, "use real 4660 transport"),
                    );
                    ui.end_row();
                });

            ui.add_space(8.0);
            ui.horizontal(|ui| {
                let can_start = !self.running();
                let can_stop = self.running() && !self.stopping;
                if ui
                    .add_enabled(can_start, egui::Button::new("Start"))
                    .clicked()
                {
                    self.start();
                }
                if ui
                    .add_enabled(can_stop, egui::Button::new("Stop"))
                    .clicked()
                {
                    self.stop();
                }
            });

            ui.add_space(6.0);
            ui.horizontal(|ui| {
                ui.strong("Status:");
                ui.label(&self.status);
            });

            ui.add_space(6.0);
            ui.separator();
            ui.label("Log");
            egui::ScrollArea::vertical()
                .auto_shrink([false, false])
                .stick_to_bottom(true)
                .show(ui, |ui| {
                    for line in &self.logs {
                        ui.monospace(line);
                    }
                });
        });

        // While a run is active, repaint periodically so new log lines and
        // status changes appear promptly without blocking the UI thread.
        if self.running() {
            ctx.request_repaint_after(Duration::from_millis(150));
        }
    }

    fn on_exit(&mut self, _gl: Option<&eframe::glow::Context>) {
        // Best-effort clean shutdown of a still-running bridge on window close.
        if let Some(control) = &self.control {
            let _ = control.shutdown.send(true);
        }
        let _ = save_settings(&self.settings);
    }
}

fn main() -> eframe::Result<()> {
    let native_options = eframe::NativeOptions {
        viewport: egui::ViewportBuilder::default().with_inner_size([540.0, 620.0]),
        ..Default::default()
    };
    eframe::run_native(
        "itec-bridge",
        native_options,
        Box::new(|cc| Box::new(BridgeApp::new(cc))),
    )
}
