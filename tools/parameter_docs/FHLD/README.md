# FlowHold Mode Configuration (FHLD)

## Overview
The **FHLD** parameter group configures the behavior of the **FlowHold** flight mode. This mode uses an **Optical Flow** sensor and a **Rangefinder** (Lidar) to hold the vehicle's position without the need for GPS.

It is ideal for indoor flight or flying in "canyons" where GPS is unreliable. FlowHold is different from standard Loiter because it doesn't require a global coordinate lock; it simply tries to keep the ground textures underneath it stationary.

## Key Concepts

### 1. Velocity Control (`FHLD_XY_P`)
This defines how aggressively the vehicle tries to correct horizontal drift.
*   **`FHLD_XY_P`**: Proportional gain. Increase for a "locked-in" feel. Decrease if the vehicle oscillates.

### 2. Quality Threshold (`FHLD_QUAL_MIN`)
Optical flow sensors require good lighting and distinct ground texture.
*   **`FHLD_QUAL_MIN`**: The minimum "confidence" score from the sensor (0-255). If quality drops below this, the vehicle will revert to Manual (AltHold) control.

### 3. Braking (`FHLD_BRAKE_RATE`)
Limits how fast the vehicle slows down when the pilot releases the sticks.

## Parameter Breakdown

*   **`FHLD_XY_P` / `I`**: Horizontal position PID gains.
*   **`FHLD_FILT_HZ`**: Cutoff frequency for the flow data filter (Hz).
*   **`FHLD_FLOW_MAX`**: Maximum expected angular flow rate.

## Integration Guide
1.  **Hardware:** Mount an Optical Flow sensor (e.g., HereFlow) and a Rangefinder.
2.  **Calibrate:** Ensure the flow sensor is calibrated correctly (rotation and scaling).
3.  **Tuning:** Start with default gains. If the vehicle drifts in FlowHold, increase `FHLD_XY_P`.

## Developer Notes
*   **Library:** `ArduCopter/mode_flowhold.cpp`.
*   **Difference:** Unlike EKF-based Loiter (which can also use Flow), FlowHold is a simpler, stand-alone mode that works even if the EKF is not fully aligned.