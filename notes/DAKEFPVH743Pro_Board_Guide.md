# Board Guide: DAKEFPV H743 Pro

**ArduPilot reference:** https://ardupilot.org/copter/docs/common-dakefpvh743pro.html
**waf board name:** `DAKEFPVH743Pro` (Pro variant) or `DAKEFPVH743` (standard)

---

## 1. Hardware Overview

| Spec | Value |
|------|-------|
| MCU | STM32H743 @ 480 MHz |
| Program flash | 2 MB (internal, same as MicoAir H743) |
| External storage | 16 MB SPI flash (logs / parameters) |
| IMU | Dual ICM42688 (SPI1 + SPI4) |
| Barometer | SPL06 |
| OSD chip | AT7456E (MAX7456 compatible) |
| Compass | **None built-in** — external I2C only |
| UARTs | 8 |
| PWM outputs | 13 (M1–M8, S1–S4, LED) |

**Key difference from MicoAir H743:** The DAKE has 16 MB external storage (no need to `--disable-scripting` for space reasons) and dual IMU. The program flash is still 2 MB so debug builds still benefit from `--disable-scripting`.

---

## 2. UART / Serial Port Assignments

| ArduPilot Serial | Hardware | Default Role |
|-----------------|----------|--------------|
| SERIAL0 | USB (OTG1) | MAVLink / GCS |
| SERIAL1 | UART1 | GPS (DMA capable) |
| SERIAL2 | UART2 | MAVLink2 |
| SERIAL3 | UART3 | ESC Telemetry |
| SERIAL4 | UART4 | DisplayPort OSD (DMA capable) |
| SERIAL5 | UART5 | **RC Input** (RX DMA capable) |
| SERIAL6 | UART6 | User |
| SERIAL7 | UART7 | User |
| SERIAL8 | UART8 | User |

**For our firmware:**
- RC Input (SBUS/ELRS): SERIAL5 — `SERIAL5_PROTOCOL = 23`
- SBUS Output to TVC/SFCs: reassign one of SERIAL6–8 — `SERIALx_PROTOCOL = 30`
- Debug logging: reassign one of SERIAL6–8 — `SERIALx_PROTOCOL = 19` (Scripting)

---

## 3. PWM Output Groups

Output protocol (DShot vs PWM) is set per timer group. You **cannot** mix DShot
and PWM on outputs sharing the same timer.

| Outputs | Timer | DShot capable? | Notes |
|---------|-------|----------------|-------|
| M1, M2 | TIM3 | Yes (BIDIR on M1) | |
| M3, M4 | TIM5 | Yes (BIDIR on M3) | |
| M5, M6 | TIM4 | Yes (BIDIR on M5) | |
| M7, M8 | TIM4 | Yes (BIDIR on M7) | same group as M5/M6 |
| S1, S2 | TIM15 | Yes (BIDIR on S1) | |
| S3, S4 | TIM8 | No (NODMA) | PWM/servo only |
| OSD pad | TIM16 | No (NODMA) | Can be used as servo output |
| LED | TIM1 | No | Serial LED or DShot |

**For our firmware:** Assign DShot motor outputs to M1–M8 (or any group above that
supports DShot). Use S3–S4 for PWM servos (tilt servo etc.) since they are on a
separate timer from the DShot motors.

Recommended parameters:
```
SERVO_BLH_MASK = [bitmask of motor output numbers using DShot]
SERVO_BLH_AUTO = 0    # Disable auto-detection to prevent accidental DShot on servos
```

---

## 4. hwdef Status in This Fork

The DAKEFPVH743Pro hwdef is present in this fork at
`libraries/AP_HAL_ChibiOS/hwdef/DAKEFPVH743Pro/`. Custom firmware can be built
directly from this branch without any cherry-pick needed.

---

## 5. One-Time System Setup (Linux)

Before flashing for the first time, install tools and configure USB permissions.

### 5.1 Install dependencies

```bash
sudo apt-get install -y dfu-util binutils   # binutils provides objcopy
```

If apt reports unmet dependencies, run `sudo apt --fix-broken install` first.

### 5.2 udev rules (flash without sudo)

```bash
sudo tee /etc/udev/rules.d/50-ardupilot.rules > /dev/null << 'EOF'
# STM32 ROM DFU mode (dfu-util first-time flash)
SUBSYSTEM=="usb", ATTR{idVendor}=="0483", ATTR{idProduct}=="df11", MODE="0664", GROUP="plugdev"
# DAKEFPV H743 Pro running ArduPilot firmware or bootloader (VID 1209:5741)
SUBSYSTEM=="tty", ATTRS{idVendor}=="1209", ATTRS{idProduct}=="5741", MODE="0664", GROUP="plugdev"
EOF
sudo udevadm control --reload-rules && sudo udevadm trigger
```

Your user must be in the `plugdev` group (check with `groups`). After adding the
rules, replug the board for them to take effect.

---

## 6. Building the Firmware

**Note on scripting:** Do **not** use `--disable-scripting`. The 6DoF attitude
controller (`AC_AttitudeControl_Multi_6DoF`) requires scripting to be enabled at
compile time. Disabling it produces a linker error.

**Note on `--debug`:** Adds debug symbols for GDB. Release builds are smaller and
are what you flash for actual flights.

```bash
# Clean any previous build artifacts (required when switching boards or flags)
./waf distclean

# --- Release build (for flying) ---
./waf configure --board DAKEFPVH743Pro
./waf copter

# --- Debug build (for GDB sessions) ---
./waf configure --board DAKEFPVH743Pro --debug
./waf copter
```

Build outputs (path reflects whichever configure was run last):
- **`arducopter_with_bl.hex`** — Intel HEX including bootloader; used as source for DFU
- **`arducopter.apj`** — firmware only (no bootloader); used for OTA updates
- **`arducopter`** — ELF with debug symbols; used with GDB (debug builds only)

---

## 7. Flashing — the `dake_flash.sh` Script

**Use `dake_flash.sh` for all flashing.** It handles build detection, DFU mode
detection, hex-to-binary conversion, and the correct tool for each path.

```bash
./dake_flash.sh           # incremental build then flash
./dake_flash.sh --build   # reconfigure + build then flash
./dake_flash.sh --flash   # flash last build without rebuilding
./dake_flash.sh --dfu     # force DFU flash (board already in DFU mode)
```

### Flashing paths

#### Path A: First-time flash (no ArduPilot bootloader installed)

The board ships with STM32 ROM DFU, not an ArduPilot bootloader. This path burns
the bootloader + firmware in one shot. After this, use Path B for all future
flashes.

Two ways to enter DFU mode:

- **Hardware:** Unplug board, hold BOOT button, plug USB back in
- **Software:** Run `./dake_flash.sh --flash` with ArduPilot running — `uploader.py`
  sends a MAVLink reboot-to-bootloader command. Even though the serial flash will
  fail (no ArduPilot bootloader), the board lands in DFU mode. Then run
  `./dake_flash.sh --dfu` to complete the flash.

Verify which mode the board is in:
```bash
lsusb | grep "0483:df11"   # ROM DFU mode (ready for dfu-util)
lsusb | grep "1209:5741"   # ArduPilot firmware/bootloader running
ls /dev/ttyACM*            # serial port present when ArduPilot is running
```

The script automatically converts `arducopter_with_bl.hex` to a raw binary via
`objcopy` before calling `dfu-util`. Passing the `.hex` file directly to
`dfu-util` does not work — it treats it as raw bytes rather than parsing Intel
HEX format.

```bash
./dake_flash.sh --dfu
# or manually:
sudo dfu-util -a 0 --dfuse-address 0x08000000:leave -D /tmp/ardupilot_dfu.bin
```

After flashing, the board boots automatically (`:leave` flag) into ArduPilot.

#### Path B: Normal OTA flash (ArduPilot bootloader installed)

Once Path A has been done once, all future flashes go through the ArduPilot
serial bootloader via USB — no BOOT button, no DFU mode needed.

```bash
./dake_flash.sh   # board must be running ArduPilot on /dev/ttyACM0
```

`uploader.py` sends a MAVLink reboot-to-bootloader command, the board reboots
into its ArduPilot bootloader (not ROM DFU), and the `.apj` firmware is uploaded
over serial. The board automatically reboots into the new firmware when done.

#### Path C: ST-Link / SWD (recovery or debug workflow)

Requires an ST-Link v2 wired to the SWD pads (see section 10). The
`micoair-h743.cfg` OpenOCD config works for all STM32H7x boards.

**IMPORTANT: Board must be in STM32 ROM DFU mode (hold BOOT + plug power) before
connecting OpenOCD.** ArduPilot remaps SWD pins at startup — OpenOCD cannot connect
to a running board.

```bash
openocd -f micoair-h743.cfg \
  -c "program build/DAKEFPVH743Pro/bin/arducopter_with_bl.hex verify reset exit"
```

OpenOCD parses Intel HEX natively — no `objcopy` conversion needed here.

---

## 8. GDB Debugging

```bash
# Terminal 1: start OpenOCD server
openocd -f micoair-h743.cfg

# Terminal 2: connect GDB
gdb-multiarch build/DAKEFPVH743Pro/bin/arducopter

# Inside GDB:
target remote :3333
break newMain           # or any other breakpoint
monitor reset halt
continue
```

---

## 9. Recommended Initial Parameters

After first flash, set these before anything else:

```
# RC Input
SERIAL5_PROTOCOL = 23       # RC Input on UART5

# Battery monitor
BATT_MONITOR = 4
BATT_VOLT_PIN = 11
BATT_CURR_PIN = 10
BATT_VOLT_MULT = 16.0
BATT_AMP_PERVLT = 83.3

# Motor output protocol — set after deciding DShot vs PWM layout
SERVO_BLH_AUTO = 0          # Disable auto-detection
```

---

## 10. SWD Pinout (for ST-Link connection)

The board exposes SWD pads. Connections to ST-Link v2:

| Board pad | ST-Link pin |
|-----------|------------|
| SWDIO | SWDIO |
| SWCLK | SWCLK |
| GND | GND |
| 3V3 | (optional — power via USB BEC instead) |

**Recommendation:** Power the board via its normal BEC/USB and connect only SWDIO,
SWCLK, and GND from the ST-Link. Avoid powering via the ST-Link 3.3V on a loaded
board.
