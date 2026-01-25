# Cloning and Flashing Guide: MicoAir H743

This guide outlines the process for cloning a "Golden Master" image onto a new flight controller and updating the firmware while preserving calibrated user data (parameters, sensor calibrations, RC setup).

## 1. Technical Concept
The H743 flash memory (2MB) is divided into:
- **Firmware (0x08000000 - 0x080FFFFF):** The compiled ArduPilot code.
- **User Data (End of Flash):** Memory regions storing parameters and calibrations.

A **Golden Master** is a raw 2MB binary dump of the entire flash. Flashing this dump creates a bit-for-bit clone. Using a `.hex` file for firmware updates allows us to overwrite the firmware region without touching the user data region.

## 2. Prerequisites
- **Hardware:** ST-Link v2 debugger.
- **Software:** `openocd` installed.
- **Configuration:** `micoair-h743.cfg` must be in the project root to handle the dual-bank flash architecture.

## 3. The "New Board" Workflow
When setting up a brand new flight controller, follow these steps to ensure it matches the master prototype.

### Step A: Boot into DFU/Bootloader Mode
To ensure a clean connection via the ST-Link:
1. Press and HOLD the physical **BOOT** button.
2. Plug in the USB cable.
3. Wait 1 second and release the button.

### Step B: Restore Golden User Data
This command flashes the 2MB raw binary dump.
```bash
openocd -f micoair-h743.cfg -c "init; program golden_master_77a622c7453d515531c14ff3bb1e12686fae3741 verify reset exit 0x08000000"
```

### Step C: Update Firmware (Preserving User Data)
Run the flashing script to load the latest compiled firmware. This uses a `.hex` file which only targets the firmware sectors.
```bash
./flash.sh
```

## 4. Creating a New Golden Master
If you have a board with perfected tuning that you wish to save as the new standard:
```bash
openocd -f micoair-h743.cfg -c "init; halt; dump_image new_golden_master.bin 0x08000000 0x200000; exit"
```

## 5. Scripted Automation (`flash.sh`)
The current `flash.sh` is configured to perform a full "Golden" restoration followed by a firmware update. This is the safest way to ensure a board is in a known-good state.

```bash
#!/bin/bash
# 1. Restore from golden master dump (2MB)
openocd -f micoair-h743.cfg -c "init; program golden_master_77a622c7453d515531c14ff3bb1e12686fae3741 verify reset exit 0x08000000"

# 2. Apply latest compiled firmware (.hex)
openocd -f micoair-h743.cfg -c "init; program arduplane_with_bl.hex verify reset exit"
```
