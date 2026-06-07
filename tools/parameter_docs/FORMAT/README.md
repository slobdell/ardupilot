# Parameter Format Version (FORMAT)

## Overview
The **FORMAT** parameter group (specifically `FORMAT_VERSION`) is an internal system identifier used by **AP_Periph** (DroneCAN) devices.

## Key Concepts

### 1. Storage Integrity
As DroneCAN peripheral firmware is updated, the way parameters are laid out in the device's internal memory (Flash/EEPROM) may change.
*   **Version Check:** At boot, the firmware checks the `FORMAT_VERSION` stored in memory.
*   **Wipe:** If the stored version does not match the version expected by the firmware, the device will automatically perform a factory reset of all parameters to prevent data corruption.

## Parameter Breakdown

*   **`FORMAT_VERSION`**: An integer representing the memory layout version.

## Developer Notes
*   **Warning:** **Do not modify.** Changing this value will cause the device to lose all calibration and configuration data on the next reboot.