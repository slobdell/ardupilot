# Mode Selection Configuration (MODE)

## Overview
The **MODE** parameter group (specifically `MODE_CH`) configures the primary method for switching between vehicle behaviors.

## Key Concepts

### 1. The Mode Channel
ArduPilot uses a designated RC input channel to select the active flight/drive mode.
*   **`MODE_CH`**: Specifies the RC channel number (1-16).
    *   **Default:** Usually 5 (for Copter/Plane) or 8 (for some Rover setups).
    *   **Logic:** The PWM value of this channel is divided into 6 segments, which are mapped to the flight modes defined in the `FLTMODE_` (or `MODE1`..`MODE6`) parameters.

## Integration Guide
*   **Setup:** Ensure your RC transmitter is mixing switches to the channel specified in `MODE_CH`.
*   **Verification:** Move the switches and verify the mode name changes in your Ground Control Station HUD.

## Developer Notes
*   **Library:** `RC_Channel::read_mode_switch()`.