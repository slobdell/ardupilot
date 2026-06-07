# LED Configuration (LED)

## Overview
The **LED** parameter group (specifically `LED_BRIGHTNESS`) configures the on-board **Status LEDs**. This is primarily used in **AP_Periph** firmware for DroneCAN nodes (like GPS modules).

## Key Concepts

### 1. Brightness Control
Allows the user to adjust the intensity of the RGB status LEDs to match ambient lighting conditions or to reduce power consumption on battery-limited devices.
*   **`LED_BRIGHTNESS`**:
    *   **100:** Full brightness.
    *   **10-50:** Dimmed for night operations or stealth.
    *   **0:** Disabled.

## Developer Notes
*   **Library:** `Tools/AP_Periph` and `libraries/AP_Notify`.
*   **Note:** Main autopilot LED brightness is typically handled in the `NTF_` group.