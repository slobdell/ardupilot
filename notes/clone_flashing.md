# Manufacturing Process: Flight Controller Cloning for Repeatable Aircraft Builds
**Document Version:** 1.0
**Date:** 2025-10-14

## 1.0 Business Objective

To scale production from a single prototype to multiple identical aircraft, we must eliminate the time-consuming and error-prone process of manually calibrating and tuning each flight controller. The current method of using Mission Planner to copy parameters is unreliable and does not clone critical sensor calibration data.

This document outlines the definitive, low-level process for creating a "Golden Master" image from a perfectly tuned flight controller and flashing it as a perfect clone onto new boards. This ensures that every aircraft produced is a 1:1 replica of the master prototype, dramatically increasing manufacturing speed, ensuring quality control, and reducing per-unit labor costs.

The use of the MicoAir H743 for both the PFC and TVC standardizes this process, allowing the same tools and procedures to be used for all controllers.

## 2.0 Core Concept: The "Golden Master" Image

The flash memory of a flight controller contains two distinct types of data:
1.  **Firmware:** The compiled ArduPilot code (`.apj` file).
2.  **User Data:** A dedicated memory region that stores all parameters, sensor calibrations (IMU, compass, etc.), RC calibration, and other settings.

High-level tools like Mission Planner interact with the User Data via the MAVLink protocol, which can be unreliable for a full backup/restore. The process outlined here bypasses MAVLink entirely. We will use a hardware debugger to read the **entire contents** of the flight controller's flash memory—both the firmware and the user data—into a single binary (`.bin`) file. This file is our "Golden Master" image.

Flashing this single file onto a new, identical board guarantees a perfect, bit-for-bit clone of the original.

## 3.0 Requirements

### 3.1 Hardware

1.  **The "Golden Master" Flight Controller:** One fully assembled, calibrated, tuned, and flight-verified MicoAir H743 board. This will be either the PFC or the TVC. The process must be done separately for each.
2.  **Target Flight Controller:** A new, unconfigured MicoAir H743 board.
3.  **Hardware Debugger:** An **ST-Link v2** debugger (or compatible clone). This is the standard tool for STM32 microcontrollers like the H743.
4.  **Cabling:** Jumper wires to connect the ST-Link to the flight controller's SWD port.

### 3.2 Software

1.  **STM32CubeProgrammer:** The official, free software from STMicroelectronics for programming STM32 microcontrollers. Downloadable from the ST website.

## 4.0 The Cloning Process

This process is divided into two phases: creating the master image (done once) and flashing the clones (done for each new aircraft).

### Phase A: Creating the Golden Master Image

This is the most critical phase. The quality of all future clones depends on the perfection of the master.

1.  **Prepare the Master Aircraft:**
    *   Perform a complete and precise calibration of all sensors: Accelerometers, Gyroscopes, and Compass.
    *   Perform the full RC radio calibration.
    *   Manually configure and tune all necessary parameters, including the custom PID gains for the TVC or the 6DOF mixer settings for the PFC.
    *   **Flight-verify all settings.** Confirm that the aircraft performs exactly as desired.

2.  **Hardware Connection:**
    *   **De-power the flight controller.**
    *   Connect the ST-Link v2 debugger to the **SWD port** on the MicoAir H743. The pinout is typically:
        *   `SWDIO` -> `SWDIO`
        *   `SWCLK` -> `SWCLK`
        *   `GND` -> `GND`
        *   `3.3V` -> `3V3` (This can power the board for flashing, but it's safer to power the board via its normal BEC and connect only SWDIO, SWCLK, and GND).
    *   Connect the ST-Link via USB to your computer.

3.  **Dump the Flash Memory:**
    *   Open STM32CubeProgrammer.
    *   In the top-right, select "ST-LINK" as the probe, and click "Connect". The programmer should detect the STM32H743 MCU.
    *   Navigate to the "Erase & Programming" tab (icon with a chip and a down arrow).
    *   In the "Download" section, specify the memory range to read:
        *   **Start address:** `0x08000000` (This is the start of flash memory for all STM32 chips).
        *   **Size:** `2 M` (The H743 has 2MB of flash).
    *   Click the "Browse" button to choose a location and name for the output file. Use a clear, version-controlled name (e.g., `PFC_GOLDEN_MASTER_v1.0.bin` or `TVC_GOLDEN_MASTER_v1.0.bin`).
    *   Click the **"Upload"** button (this means upload *from* the board *to* the PC).
    *   The process will take a few moments. Once complete, you will have the Golden Master binary file.
    *   **Store this file in a safe, version-controlled location.** This file is a critical manufacturing asset.

### Phase B: Flashing Clones

This is the repeatable process for each new aircraft.

1.  **Hardware Connection:** Connect the ST-Link to the new, blank MicoAir H743 board as described above.
2.  **Program the Clone:**
    *   Open STM32CubeProgrammer and connect to the board.
    *   Navigate to the "Erase & Programming" tab.
    *   Click **"Full chip erase"** and wait for it to complete. This ensures a clean slate.
    *   In the "Download" section, click "Browse" and select your saved `_GOLDEN_MASTER_v1.0.bin` file.
    *   Ensure the start address is `0x08000000`.
    *   Check the **"Verify after programming"** box. This is a critical quality control step that ensures the data was written correctly.
    *   Click the **"Start Programming"** button.
    *   The process will erase, program, and verify the flash. Once it succeeds, the new board is a perfect clone.

## 5.0 Critical Considerations & Quality Control

*   **Hardware Consistency:** This entire process relies on the MicoAir H743 boards being **absolutely identical**. If the manufacturer changes the IMU sensor, flash memory chip, or any other critical component between batches, a cloned image may not work correctly. All boards used for production must be from the same validated batch.
*   **Firmware Updates:** This process flashes the entire chip, including the bootloader. To update the ArduPilot firmware on your fleet, you cannot simply use Mission Planner. You must build a **new Golden Master** with the new firmware, re-verify its performance, and then use this new master image to re-flash all the aircraft.
*   **Version Control:** Maintain strict version control of your Golden Master binary files. A change in any parameter or firmware version requires the creation of a new, clearly named file (e.g., `PFC_GOLDEN_MASTER_v1.1_PID_Update.bin`).
