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

The DAKEFPVH743Pro hwdef exists in upstream ArduPilot (`origin/master`) but has
**not been merged into this fork** (`fork/slobdell_base`). Before you can build
custom firmware for this board from the fork, the hwdef must be cherry-picked in:

```bash
# From the fork/slobdell_base branch, cherry-pick the upstream hwdef commit:
git cherry-pick <commit-hash-of-AP_HAL_ChibiOS-add-DAKEFPVH743>

# Or copy the hwdef directory manually from upstream:
git show origin/master:libraries/AP_HAL_ChibiOS/hwdef/DAKEFPVH743Pro > ...
```

The relevant upstream commits are (from `git log --oneline origin/master`):
- `AP_HAL_ChibiOS: add DAKEFPVH743` — adds the standard and Pro hwdefs
- `Tools: add DAKEFPVH743` — adds bootloaders

Until the hwdef is merged, you can still flash **stock ArduPilot firmware** (from
firmware.ardupilot.org) and use QGC/Mission Planner for parameter configuration.

---

## 5. Building the Firmware

Once the hwdef is present in the fork:

```bash
# From the repo root — clean any previous build artifacts
./waf distclean

# Configure for the DAKE Pro with debug symbols
# --disable-scripting saves ~200 KB, useful for debug builds on 2 MB flash
./waf configure --board DAKEFPVH743Pro --debug --disable-scripting

# Build ArduCopter
./waf copter
```

Build outputs:
- **Firmware:** `build/DAKEFPVH743Pro/bin/arducopter_with_bl.hex` — use for first flash
- **Firmware (no BL):** `build/DAKEFPVH743Pro/bin/arducopter.apj` — use for OTA updates
- **Debug symbols:** `build/DAKEFPVH743Pro/bin/arducopter` — ELF file for GDB

---

## 6. Flashing Methods

### Method A: DFU (First-Time / Bootloader Flash)

Use this when the board has no ArduPilot bootloader, or to recover a bricked board.

1. Unplug the board from USB.
2. Hold the **BOOT button** on the board.
3. While holding BOOT, plug in USB — the board enters DFU mode.
4. Verify it appears as a DFU device:
   ```bash
   lsusb | grep DFU
   # or
   dfu-util -l
   ```
5. Flash the full firmware including bootloader:
   ```bash
   dfu-util -a 0 --dfuse-address 0x08000000 -D build/DAKEFPVH743Pro/bin/arducopter_with_bl.hex
   ```
6. Unplug and replug — board boots into ArduPilot.

### Method B: ST-Link / SWD (Developer Workflow)

For rapid build-flash-debug cycles. Requires an ST-Link v2 and the SWD pads on
the board. The `micoair-h743.cfg` OpenOCD config works for all STM32H7x boards.

```bash
# Flash (from repo root)
openocd -f micoair-h743.cfg \
  -c "program build/DAKEFPVH743Pro/bin/arducopter_with_bl.hex verify reset exit"
```

For a one-step build + flash:
```bash
./waf copter && \
openocd -f micoair-h743.cfg \
  -c "program build/DAKEFPVH743Pro/bin/arducopter_with_bl.hex verify reset exit"
```

### Method C: OTA via Ground Station (Firmware Updates)

Once ArduPilot is running, use Mission Planner or QGroundControl:
- Connect via USB or telemetry
- Use the `.apj` file: `build/DAKEFPVH743Pro/bin/arducopter.apj`
- Or point the GCS at firmware.ardupilot.org for stock releases

**Note:** OTA updates do not erase parameters or calibration data, unlike a full
ST-Link flash of `with_bl.hex` which flashes the entire chip.

---

## 7. GDB Debugging

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

## 8. Recommended Initial Parameters

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

## 9. SWD Pinout (for ST-Link connection)

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
