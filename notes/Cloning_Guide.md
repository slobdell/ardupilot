# Flight Controller Cloning & Flashing Guide

**Target Hardware:** MicoAir H743 (STM32H743)

The H743 flash (2 MB) holds two distinct regions:
- **Firmware (`0x08000000–0x080FFFFF`):** Compiled ArduPilot code.
- **User Data (end of flash):** Parameters, sensor calibrations, RC setup.

A **Golden Master** is a raw 2 MB binary dump of the entire flash. Restoring it gives a bit-for-bit clone of the source board, including all calibrations. Flashing a `.hex` or `.apj` file only touches the firmware region, leaving user data intact.

---

## 1. Prerequisites

### Hardware
- ST-Link v2 debugger (or compatible clone)
- Jumper wires for SWD connection

### Software
```bash
sudo apt-get update
sudo apt-get install -y openocd gcc-arm-none-eabi gdb-arm-none-eabi
```

A `micoair-h743.cfg` file must be present in the project root — it handles the dual-bank flash architecture that OpenOCD does not auto-detect on the H743.

---

## 2. Forcing Connection: DFU Mode

ArduPilot remaps the SWD pins (PA13/PA14) at startup, preventing OpenOCD from connecting to a running board. Always boot into ROM DFU mode before using the ST-Link.

1. Unplug power from the board.
2. Press and **hold** the physical **BOOT** button.
3. While holding BOOT, plug power back in via USB.
4. Release the button after 1 second.

Verify:
```bash
lsusb | grep "0483:df11"   # STM32 ROM DFU mode — ready for OpenOCD
```

---

## 3. ST-Link Wiring (SWD Port)

| Board pad | ST-Link pin |
|-----------|-------------|
| SWDIO (PA13) | SWDIO |
| SWCLK (PA14) | SWCLK |
| GND | GND |

Power the board via its normal USB/BEC. Do **not** use the ST-Link 3.3V pin to power a loaded board.

---

## 4. Memory Map

| Region | Start address | Size |
|--------|--------------|------|
| Bank 1 (firmware + bootloader) | `0x08000000` | 1 MB (`0x100000`) |
| Bank 2 (firmware + user data)  | `0x08100000` | 1 MB (`0x100000`) |
| Full flash (both banks) | `0x08000000` | 2 MB (`0x200000`) |

**H743 dual-bank caveat:** OpenOCD often fails to auto-detect Bank 2. The `micoair-h743.cfg` config handles this. If using the raw `stm32h7x.cfg` instead, you must manually define the second bank:
```bash
-c "flash bank bank1 stm32h7x 0x08100000 0x100000 0 0 stm32h7x.cpu0"
```

---

## 5. Creating a Golden Master

Connect the fully tuned, calibrated, and flight-verified board. Board must be in DFU mode (see Section 2) with ST-Link connected.

```bash
openocd -f micoair-h743.cfg -c "init; halt; dump_image golden_master.bin 0x08000000 0x200000; exit"
```

Name the output file clearly and store it in version control (e.g., `golden_master_<git-hash>.bin`). This file is a critical manufacturing asset — treat it like source code.

---

## 6. Restoring a Golden Master (Full Clone)

Connect the target board (new or recovery). Board must be in DFU mode with ST-Link connected.

```bash
openocd -f micoair-h743.cfg -c "init; program golden_master_<hash> verify reset exit 0x08000000"
```

The `verify` flag confirms the write succeeded before resetting. After restore, unplug and replug USB — the board boots with all firmware, calibrations, and parameters from the master.

**Note:** This overwrites everything including parameters. After restore, verify your parameter state:
```bash
python3 tools/mavlink/param_apply.py params/<aircraft>.param --dry-run
```

---

## 7. OTA Firmware Flash (Preserves User Data)

Use this for routine firmware updates on a board that is already configured. The board must be running ArduPilot on `/dev/ttyACM0` — no ST-Link required.

```bash
./micoair_flash.sh --flash
```

This uses `uploader.py` to send a MAVLink reboot-to-bootloader command, uploads the firmware over serial, and reboots into the new firmware. Parameters and calibrations are untouched.

---

## 8. Quality Control

- **Hardware consistency:** Cloned images require identical hardware. If the manufacturer changes the IMU, flash chip, or other components between batches, a cloned image may not work. Validate all boards from the same batch before production.
- **Firmware updates on a cloned fleet:** Updating firmware via OTA (Section 7) works per-board and is the preferred method. Alternatively, create a new Golden Master with the updated firmware, re-verify, and re-clone.
- **Version control:** Keep golden master binaries in the repo with descriptive names. A parameter or firmware change warrants a new file (e.g., `golden_master_<new-hash>.bin`).

---

## 9. Troubleshooting

**"Target Not Found" or "Connection Failed"**
- Check wiring — SWDIO and SWCLK are commonly swapped.
- Confirm the board is in DFU mode (`lsusb | grep "0483:df11"`).
- Try lowering adapter speed: add `-c "adapter speed 2000"` before `init`.

**"Flash Write Failed" or "No flash bank found"**
- The H743 option bytes may be protecting sectors. Add a mass erase before programming:
  `-c "stm32h7x mass_erase 0"`
- If Bank 2 is missing, ensure `micoair-h743.cfg` is being used (not the raw `stm32h7x.cfg`).

**Verifying board state**
```bash
lsusb | grep "0483:df11"   # ROM DFU mode — ready for OpenOCD
lsusb | grep "1209:5741"   # ArduPilot running
lsusb | grep "0483:3748"   # ST-Link v2 detected
```
