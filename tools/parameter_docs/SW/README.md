# Switch Method Configuration (SW)

## Overview
The **SW** parameter group (specifically `SW_METHOD` or `OSD_SW_METHOD`) defines how the pilot toggles through different **OSD Screens**.

## Key Concepts

### 1. Screen Selection
ArduPilot supports multiple OSD layouts. This parameter selects the trigger for switching between them.
*   **`SW_METHOD`**:
    *   **0:** Fixed (Only Screen 1).
    *   **1:** Use an RC Channel (defined in `OSD_CHAN`).
    *   **2:** Toggle on a switch change.
    *   **3:** Automatic (Switch based on flight stage: Arming/Failsafe/Mission).

## Developer Notes
*   **Library:** `libraries/AP_OSD`.