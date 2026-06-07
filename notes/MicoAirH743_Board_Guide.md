# Board Guide: MicoAir H743

---

## 1. Hardware Overview

| Spec | Value |
|------|-------|
| MCU | STM32H743 @ 480 MHz |
| Program flash | 2 MB (internal only — no external flash) |
| IMU | Single IMU |
| Compass | IST8310 (built-in) |
| UARTs | 8 |

**Key difference from DAKE:** Has a built-in IST8310 compass. No external SPI flash,
so `--disable-scripting` is required to fit the firmware in 2 MB.

---

## 2. UART / Serial Port Assignments

| ArduPilot Serial | Hardware | Role in our firmware |
|-----------------|----------|----------------------|
| SERIAL1 | UART1 | SBUS Bus A output to TVC & SFCs (`PROTOCOL=30`) |
| SERIAL4 | UART4 | Custom debug/logging (`PROTOCOL=19`) |
| SERIAL5 | UART6 | RC Input from receiver (`PROTOCOL=23`) |

---

## 3. One-Time System Setup (Linux)

Install tools and configure USB permissions (same as DAKE — skip if already done).

### 3.1 Install dependencies

```bash
sudo apt-get install -y openocd binutils
```

### 3.2 udev rules (run without sudo)

```bash
sudo tee /etc/udev/rules.d/50-ardupilot.rules > /dev/null << 'EOF'
# STM32 ROM DFU mode
SUBSYSTEM=="usb", ATTR{idVendor}=="0483", ATTR{idProduct}=="df11", MODE="0664", GROUP="plugdev"
# ST-Link v2
SUBSYSTEM=="usb", ATTR{idVendor}=="0483", ATTR{idProduct}=="3748", MODE="0664", GROUP="plugdev"
# MicoAir / DAKE running ArduPilot firmware or bootloader (VID 1209:5741)
SUBSYSTEM=="tty", ATTRS{idVendor}=="1209", ATTRS{idProduct}=="5741", MODE="0664", GROUP="plugdev"
EOF
sudo udevadm control --reload-rules && sudo udevadm trigger
```

Replug the board after running.

---

## 4. Building the Firmware

`--disable-scripting` is required — the Lua runtime does not fit in 2 MB alongside
the firmware.

```bash
./waf distclean   # required when switching from another board
./waf configure --board MicoAir743 --disable-scripting
./waf copter
```

Build outputs:
- **`arducopter_with_bl.hex`** — full flash image including bootloader
- **`arducopter.apj`** — firmware only; used for OTA updates (preserves parameters)
- **`arducopter`** — ELF with debug symbols; used with GDB

---

## 5. Flashing — the `micoair_flash.sh` Script

```bash
./micoair_flash.sh              # incremental build then OTA flash
./micoair_flash.sh --build      # reconfigure + build then OTA flash
./micoair_flash.sh --flash      # OTA flash last build without rebuilding
./micoair_flash.sh --restore    # restore golden master via ST-Link (full chip)
```

### Path A: OTA flash (normal workflow)

Board must be running ArduPilot on `/dev/ttyACM0`. Fast, preserves parameters.

```bash
./micoair_flash.sh
```

`uploader.py` sends a MAVLink reboot-to-bootloader command, the board reboots into
its ArduPilot bootloader, firmware is uploaded over serial, board reboots into new
firmware. Parameters and calibrations are untouched.

Verify board is present before flashing:
```bash
lsusb | grep "1209:5741"   # ArduPilot running
ls /dev/ttyACM*
```

### Path B: Golden master restore (ST-Link / recovery)

Use this to restore a known-good full flash image including calibrated parameters.
The golden master file is `golden_master_77a622c7453d515531c14ff3bb1e12686fae3741`
(from commit "blimp works entirely", Jan 2026).

**IMPORTANT: Board must be in STM32 ROM DFU mode before connecting OpenOCD.**
ArduPilot remaps the SWD pins (PA13/PA14) at startup, preventing OpenOCD from
connecting to a running board.

To enter ROM DFU mode:
1. Unplug power from the board
2. Hold the **BOOT button**
3. While holding BOOT, plug power back in
4. Verify: `lsusb | grep "0483:df11"`

Then connect the ST-Link SWD wires and run:
```bash
./micoair_flash.sh --restore
```

**ST-Link wiring:**

| Board pad | ST-Link pin |
|-----------|-------------|
| SWDIO (PA13) | SWDIO |
| SWCLK (PA14) | SWCLK |
| GND | GND |

Power the board via its normal USB/BEC — do NOT use ST-Link 3.3V to power a loaded board.

After restore, unplug and replug USB — the board boots into ArduPilot with all
calibrations and parameters from the golden master.

---

## 6. GDB Debugging

```bash
# Terminal 1 — board must be in ROM DFU mode (BOOT button), ST-Link connected
openocd -f micoair-h743.cfg

# Terminal 2
gdb-multiarch build/MicoAir743/bin/arducopter
target remote :3333
break newMain
monitor reset halt
continue
```

---

## 7. Identifying Board State

```bash
lsusb | grep "0483:df11"   # ROM DFU mode (BOOT button held) — ready for OpenOCD
lsusb | grep "1209:5741"   # ArduPilot firmware or bootloader running
lsusb | grep "0483:3748"   # ST-Link v2 detected
ls /dev/ttyACM*            # serial port present when ArduPilot is running
```
