# Control Scaling Configuration (SCALING)

## Overview
The **SCALING** parameter group (specifically `SCALING_SPEED`) is a fundamental configuration for **ArduPlane** (Fixed-Wing).

Aerodynamics are highly speed-dependent. As a plane flies faster, the same amount of control surface movement (e.g., 5 degrees of aileron) produces significantly more roll force. To maintain stable flight across a wide speed range, the autopilot must automatically scale (reduce) its servo movements as airspeed increases.

## Key Concepts

### 1. Speed Scaling
*   **`SCALING_SPEED`**: The "Reference Speed" (m/s) at which your tuned PID gains are exactly 100% effective.
    *   **Cruise:** Usually set to your typical cruise speed.
    *   **Autotune:** Automatically set by the Autotune process to the speed at which the tune was performed.

### 2. The Inverse Relationship
The autopilot calculates a multiplier: `Scaler = SCALING_SPEED / Current_Airspeed`.
*   **Faster:** If the plane flies twice as fast as `SCALING_SPEED`, the control movements are cut in half.
*   **Slower:** If the plane flies slower, the control movements increase to maintain authority.

## Developer Notes
*   **Library:** `ArduPlane/Attitude.cpp`.
*   **Fallback:** If no airspeed sensor is present, the system uses a throttle-based estimation of speed scaling.