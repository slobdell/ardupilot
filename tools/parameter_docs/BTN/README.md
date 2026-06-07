# Button Input Configuration (BTN)

## Overview
The **BTN** parameter group configures up to 4 physical push-buttons connected to the autopilot's GPIO pins. These buttons can be used to trigger flight mode changes, relay toggles, camera actions, or safety functions without needing an RC transmitter.

**Note:** This is for *physical* buttons on the drone, not buttons on your RC controller (see `RCx_OPTION`) or Joystick (see `JS_BUTTON`).

## Key Concepts

### 1. Function Mapping (`BTN_FUNCn`)
Assigns an action to the button press.
*   **Disabled:** Do nothing.
*   **Mode Change:** Switch to Loiter, RTL, Auto, etc.
*   **Camera:** Trigger shutter.
*   **Relay:** Toggle a relay pin.
*   **Arm/Disarm:** Toggle arming state (dangerous).

### 2. Shift Functions (`BTN_SFUNCn`)
Allows a button to perform a *different* action if a designated "Shift" button is held down simultaneously.

## Parameter Breakdown

*   **`BTN_ENABLE`**: Master switch.
*   **`BTN_PINn`**: GPIO/Servo pin number connected to the button.
*   **`BTN_FUNCn`**: Primary action.
*   **`BTN_OPTIONSn`**: Debounce logic and active high/low settings.

## Integration Guide
1.  **Hardware:** Connect a momentary switch between a Signal Pin and Ground.
2.  **Enable:** Set `BTN_ENABLE = 1`.
3.  **Map Pin:** Set `BTN_PIN1` to the servo rail pin number (e.g., 50 for AUX1).
4.  **Set Function:** Set `BTN_FUNC1` to the desired action.
5.  **Test:** Press the button and check the GCS "Messages" tab for confirmation.

## Developer Notes
*   **Library:** `libraries/AP_Button`
*   **Polling:** Buttons are polled at 10Hz-50Hz.