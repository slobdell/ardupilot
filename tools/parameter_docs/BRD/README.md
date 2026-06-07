# Board Configuration (BRD)

## Overview
The **BRD** parameter group contains **Hardware Abstraction Layer (HAL)** settings. These parameters configure the low-level behavior of the flight controller board itself, independent of the vehicle type (Copter/Plane/Rover).

It handles IO processor communication, safety switches, internal heating, SD card speeds, and board-specific voltage monitoring.

## Key Concepts

### 1. Safety Switch (`BRD_SAFETY_DEFLT` / `BRD_SAFETY_MASK`)
Controls the behavior of the hardware Safety Switch (often on the GPS module).
*   **Default:** Determines if the safety switch is active at boot.
*   **Mask:** Allows specific channels (e.g., landing gear, gimbal) to move even when the safety switch is active (safe).

### 2. IMU Heater (`BRD_HEAT_...`)
Many high-end boards (Cube, Durandal) have internal heating resistors to keep the IMU at a constant temperature (usually 45-60°C) for consistent calibration.
*   **Tuning:** `BRD_HEAT_P/I` controls the PID loop for the heater.

### 3. IO Processor (`BRD_IO_ENABLE`)
Some boards (Pixhawk 1/Cube) use a separate co-processor (IOMCU) for PWM output safety.
*   **`BRD_IO_ENABLE`**: Must be 1 to use the MAIN/AUX output split on IOMCU-equipped boards.

### 4. SD Card (`BRD_SD_SLOWDOWN`)
If you have logging issues or bad SD cards, this parameter can slow down the SPI clock to the card to improve reliability (at the cost of speed).

## Parameter Breakdown

*   **`BRD_TYPE`**: Autodetected board ID. Read-only.
*   **`BRD_SERIAL_NUM`**: Unique ID of the board.
*   **`BRD_BOOT_DELAY`**: Delays bootup to allow peripherals (sensors) to power up and stabilize.
*   **`BRD_PWM_VOLT_SEL`**: Selects 3.3V or 5V for servo rail output (if supported by hardware hardware).

## Integration Guide

### Disabling the Safety Switch
If you don't have a switch installed and the board refuses to arm ("Hardware Safety Switch"):
1.  Set `BRD_SAFETY_DEFLT = 0`.
2.  Reboot.

### SD Card Issues
If you see "No SD Card" or logging gaps:
1.  Try `BRD_SD_SLOWDOWN = 1` or higher.

## Developer Notes
*   **Library:** `libraries/AP_HAL_ChibiOS` (mostly).
*   **Scope:** These are often set by `hwdef.dat` at compile time but can be overridden.