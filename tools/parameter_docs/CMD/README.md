# Mission Command Status (CMD)

## Overview
The **CMD** parameter group (specifically `CMD_TOTAL`) is a read-only reporting mechanism for the onboard mission storage.

## Key Concepts

### 1. Mission Storage
ArduPilot stores mission items (Waypoints, Do-Jumps, ROI, etc.) in EEPROM or FRAM. This parameter simply reports how many items are currently valid and loaded.

## Parameter Breakdown

*   **`CMD_TOTAL`**: The total count of mission items stored on the vehicle.
    *   **0:** No mission loaded (or only Home).
    *   **>0:** Valid mission present.

## Integration Guide
*   **Usage:** Ground Control Stations check this value to verify that a "Write Waypoints" operation was successful.
*   **Do Not Edit:** Changing this manually will corrupt the mission index.

## Developer Notes
*   **Library:** `libraries/AP_Mission`