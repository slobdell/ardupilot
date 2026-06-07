# RC Input Configuration (RC)

## Overview
The **RC** parameter group configures how the autopilot interprets signals from the **Radio Control (RC)** receiver. It handles channel calibration (Min/Max/Trim), reversal, and the assignment of auxiliary functions to transmitter switches.

ArduPilot supports up to 16 RC input channels.

## Key Concepts

### 1. Channel Calibration (`RCn_MIN`, `RCn_MAX`, `RCn_TRIM`)
Defines the pulse-width range (PWM in microseconds) for each stick and switch.
*   **`MIN`**: Pulse width at lowest stick position (typically ~1000us).
*   **`MAX`**: Pulse width at highest stick position (typically ~2000us).
*   **`TRIM`**: Pulse width at center/neutral position (typically ~1500us).
*   **`DZ`**: Deadzone. Small range around the center where stick movement is ignored to prevent "jitter" or "drift."

### 2. Auxiliary Functions (`RCn_OPTION`)
This is the most powerful feature of the RC system. You can map any of ArduPilot's hundreds of functions to a switch on your transmitter.
*   **Common Options:**
    *   7: Do Nothing.
    *   22: Parachute Release.
    *   28: Gripper.
    *   300: Camera Trigger.

### 3. Failsafe (`RC_FS_...`)
Configures how the autopilot detects that the radio link has been lost.
*   **`RC_FS_TIMEOUT`**: How many seconds of no signal before triggering a failsafe action.

## Parameter Breakdown

*   **`RC_PROTOCOLS`**: Bitmask to select which digital protocols to search for (SBUS, CRSF, FPort, etc.).
*   **`RC_OPTIONS`**: Bitmask for specialized input behaviors (e.g., ignore receiver failsafe bit).
*   **`RC_SPEED`**: Update rate for standard PWM inputs (Hz).

## Integration Guide
1.  **Calibration:** Always perform "RC Calibration" in your GCS whenever you change your transmitter settings or receiver.
2.  **Assignment:** Use the "Radio Calibration" or "Extended Tuning" screens to assign switch functions (`RCn_OPTION`).
3.  **Reverse:** If the HUD shows the drone tilting the wrong way, use `RCn_REVERSED`.

## Developer Notes
*   **Library:** `libraries/AP_RCProtocol`.
*   **Filtering:** Input signals are low-pass filtered to reduce noise.