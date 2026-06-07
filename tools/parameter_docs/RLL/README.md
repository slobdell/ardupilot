# Roll Controller Configuration (RLL)

## Overview
The **RLL** parameter group (often appearing as `RLL_` or `RLL2SRV_`) configures the **Roll Attitude Controller** for **ArduPlane**.

This library is responsible for maintaining the requested bank angle (e.g., "Bank 30 degrees left") and managing the rotation rate of the aircraft by driving the aileron servos.

## Key Concepts

### 1. Roll-to-Servo (`RLL2SRV_...`)
The core PID controller for fixed-wing roll.
*   **`RLL2SRV_P/I/D`**: Standard PID gains.
*   **`RLL2SRV_TCONST`**: The time constant (seconds) for the roll response. Defines how long it takes to reach 63% of the target angle.

### 2. Rate Limits (`RLL2SRV_RMAX`)
Defines the maximum physical roll rate (deg/s) the autopilot is allowed to request. This protects the airframe from over-stress and ensures the pilot stays within safe maneuvering limits.

## Parameter Breakdown

*   **`RLL2SRV_P`**: Proportional gain.
*   **`RLL2SRV_TCONST`**: Speed of response (typically 0.4s to 0.7s).
*   **`RLL_RATE_P`**: (If present) Direct gyro-rate feedback gain.

## Integration Guide
*   **Tuning:** Use **AUTOTUNE** in ArduPlane. It will automatically find the best `RLL2SRV_P`, `I`, and `D` values by performing a series of controlled rolls.
*   **Oscillation:** If the plane "waggles" its wings rapidly in FBWA mode, reduce `RLL2SRV_P` or increase `RLL2SRV_TCONST`.

## Developer Notes
*   **Library:** `libraries/APM_Control/AP_RollController.cpp`.