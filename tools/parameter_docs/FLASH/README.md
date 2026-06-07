# Flash Memory & Bootloader (FLASH)

## Overview
The **FLASH** parameter group provides tools for managing the on-board non-volatile memory (Flash) of the autopilot or peripheral.

Currently, this is primarily used within **AP_Periph** firmware to trigger critical bootloader updates.

## Key Concepts

### 1. Bootloader Update (`FLASH_BOOTLOADER`)
The bootloader is the first bit of code that runs when the board powers up. Updating it is risky but sometimes necessary to support new firmware features or hardware fixes.
*   **Trigger:** Setting `FLASH_BOOTLOADER = 1` tells the firmware to overwrite the bootloader sector with an updated version embedded in the application binary.

## Parameter Breakdown

*   **`FLASH_BOOTLOADER`**:
    *   **0:** Idle.
    *   **1:** Perform update on next boot.

## Integration Guide
*   **Safety:** **DO NOT** trigger a bootloader update unless specifically instructed by firmware release notes. A power failure during this process can "brick" the device, requiring an ST-Link or JTAG debugger to recover.

## Developer Notes
*   **Library:** `Tools/AP_Periph`.