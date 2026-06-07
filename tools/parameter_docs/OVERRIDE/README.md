# Input Override Configuration (OVERRIDE)

## Overview
The **OVERRIDE** parameter group (specifically `OVERRIDE_CHAN`) configures the manual override safety feature for **ArduCopter**.

## Key Concepts

### 1. The Override Channel
In some complex setups (like using a Joystick or external script for navigation), it is important to have a physical switch that "Forces" the autopilot to ignore the external inputs and return control to the pilot's RC transmitter.
*   **`OVERRIDE_CHAN`**: Specifies the RC channel (1-16) mapped to an "External Input Enable" switch.
    *   **Low:** Autopilot uses external MAVLink control.
    *   **High:** Autopilot ignores external control and follows the RC stick positions.

## Developer Notes
*   **Library:** `libraries/AP_RCProtocol`.
*   **Safety:** Critical for testing new companion computer code; allows the pilot to "take back the drone" instantly if the software malfunctions.