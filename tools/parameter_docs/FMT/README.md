# Format Configuration (FMT)

## Overview
The **FMT** parameter group (specifically `FMT_VER` or `FORMAT_VERSION`) is an internal system parameter for **AP_Periph** (DroneCAN) hardware.

## Key Concepts

### 1. Storage Versioning
As firmware evolves, the way parameters are stored in Flash memory might change.
*   **`FMT_VER`**: An integer that tells the firmware which "layout" of parameters is currently on the chip.
*   **Mismatch Behavior:** If you flash new firmware that expects Format 2, but the chip has Format 1, the firmware will detect the mismatch and perform a "Factory Reset" (EEPROM wipe) to ensure data integrity.

## Parameter Breakdown

*   **`FMT_VER`**: Internal format version number.

## Integration Guide
*   **Warning:** **Do not edit manually.** Changing this value will likely wipe all your settings on the next reboot.

## Developer Notes
*   **Library:** `Tools/AP_Periph`.