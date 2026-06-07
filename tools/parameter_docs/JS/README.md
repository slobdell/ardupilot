# Joystick Configuration (JS)

## Overview
The **JS** parameter group configures the behavior of a **USB Joystick or Gamepad** when used as the primary control interface. This is most common in **ArduSub** (ROV) and some Ground Vehicle setups where a traditional RC transmitter is not used.

The joystick commands are sent from the GCS (Mission Planner/QGC) to the autopilot via MAVLink `MANUAL_CONTROL` messages.

## Key Concepts

### 1. Gain Control (`JS_GAIN_...`)
Because joysticks often have shorter travel than RC sticks, or are used in sensitive environments, the system uses a "Gain" to scale the inputs.
*   **`JS_GAIN_DEFAULT`**: The multiplier applied to all sticks at startup.
*   **`JS_GAIN_STEPS`**: The number of increments used when the pilot uses "Gain Up/Down" buttons on the gamepad.

### 2. Thrust Scaling (`JS_THR_GAIN`)
Specific scaling for the throttle/vertical axis, allowing for fine depth control while maintaining high horizontal maneuverability.

## Parameter Breakdown

*   **`JS_GAIN_DEFAULT`**: Starting gain (e.g., 0.5 = 50% power).
*   **`JS_GAIN_MAX`**: Maximum allowable gain.
*   **`JS_GAIN_MIN`**: Minimum gain.

## Integration Guide
1.  **Hardware:** Plug a gamepad into your PC running the GCS.
2.  **Calibrate:** Perform "Joystick Calibration" in the GCS.
3.  **Functions:** Map gamepad buttons to ArduPilot functions (e.g., `Arm`, `Mode Change`, `Gripper`).
4.  **Tuning:** Use the gain buttons in-mission to adjust sensitivity based on current conditions (e.g., lower gain for precise work near a structure).

## Developer Notes
*   **Library:** `ArduSub` (mostly).
*   **Logic:** Input is received via `GCS_MAVLINK::handle_manual_control()`.