# Camera Trigger Configuration (CAM)

## Overview
The **CAM** parameter group configures the **Camera Trigger** system for aerial mapping and photography. It allows the autopilot to automatically trigger the camera shutter at precise distance intervals (`CAM_TRIGG_DIST`) or via RC commands.

ArduPilot supports up to 2 simultaneous cameras (`CAM1` and `CAM2`).

## Key Concepts

### 1. Trigger Type (`CAM_TYPE`)
How does the autopilot talk to the camera?
*   **0:** Disabled.
*   **1 (Servo):** PWM pulse on a servo rail pin (e.g., IR trigger, Sony Multiport).
*   **2 (Relay):** Hard high/low voltage toggle (e.g., CHDK).
*   **4 (Mount):** Sends "Shoot" command to the connected Gimbal/Mount.
*   **5 (MAVLink):** Sends `CAMERA_TRIGGER` MAVLink message to a smart camera.

### 2. Distance Triggering (`CAM_TRIGG_DIST`)
The core feature for mapping. The autopilot tracks the distance traveled ("Ground Distance") and triggers the camera every X meters to ensure consistent overlap.
*   **`CAM_AUTO_ONLY`**: If enabled, distance triggering only works in Auto mode (safety).

### 3. Feedback (`CAM_FEEDBAK_PIN`)
For high-precision RTK mapping (PPK), the autopilot needs to know exactly when the shutter opened, not just when the command was sent.
*   Connect the camera's "Hotshoe" flash output to a digital input pin.
*   The autopilot logs the precise GPS time of the flash in the `CAM` log message.

## Parameter Breakdown

*   **`CAM_DURATION`**: How long to hold the button down (Relay/Servo).
*   **`CAM_SERVO_ON` / `OFF`**: PWM values for "Push" and "Release".
*   **`CAM_MIN_INTERVAL`**: Minimum time between shots (prevents buffer overflow).

## Integration Guide

### Setting up a Servo Trigger
1.  **Pin:** Map a servo output to `CameraTrigger` (Function 10).
2.  **Type:** Set `CAM_TYPE = 1`.
3.  **Values:** Set `CAM_SERVO_ON` to the PWM that fires the shutter (e.g., 1900) and `OFF` to neutral (e.g., 1100).
4.  **Test:** Use "Trigger Camera NOW" in the GCS.

## Developer Notes
*   **Library:** `libraries/AP_Camera`
*   **Logging:** Generates `TRIG` (commanded) and `CAM` (feedback) log messages.