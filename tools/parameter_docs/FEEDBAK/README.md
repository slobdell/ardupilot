# Camera Feedback Configuration (FEEDBAK)

## Overview
The **FEEDBAK** parameter group (often appearing as `CAM_FEEDBAK_` in the full parameter list) configures the high-precision **Camera Shutter Feedback** system.

For professional aerial mapping (PPK/RTK), it is not enough to know when the autopilot *commanded* a photo; you must know exactly when the shutter *actually opened*. This system listens for a hardware signal from the camera (usually via the Hotshoe or Flash port) to record a precise GPS time-stamp.

## Key Concepts

### 1. Feedback Pin (`FEEDBAK_PIN`)
The GPIO/Digital input pin on the flight controller connected to the camera's feedback line.

### 2. Polarity (`FEEDBAK_POL`)
Defines whether the autopilot looks for a Low-to-High (Rising) or High-to-Low (Falling) voltage edge.
*   **0:** Active Low.
*   **1:** Active High.

## Parameter Breakdown

*   **`FEEDBAK_PIN`**: GPIO pin number.
*   **`FEEDBAK_POL`**: Trigger edge polarity.

## Integration Guide
1.  **Hardware:** Wire the camera's hotshoe adapter to a digital input.
2.  **Config:** Set `CAM_FEEDBAK_PIN` to the input pin ID.
3.  **Verify:** Check the DataFlash log for `CAM` messages. The time difference between `TRIG` (command) and `CAM` (feedback) represents the total system latency.

## Developer Notes
*   **Library:** `libraries/AP_Camera`.
*   **Accuracy:** This signal is handled via interrupt or high-frequency polling to ensure microsecond-level accuracy for post-processed kinematics (PPK).