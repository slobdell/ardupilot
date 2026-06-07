# Steering Controller Configuration (STEER2SRV)

## Overview
The **STEER2SRV** parameter group (often appearing as `STEER2SRV_` or `STR_`) configures the **Lateral Steering Controller** for **ArduRover** and for ground steering in **ArduPlane**.

This library is responsible for maintaining the requested heading or following a navigation line by driving the steering servo or motor differential.

## Key Concepts

### 1. Steering-to-Servo (`STEER2SRV_...`)
The core PID controller for ground steering.
*   **`STEER2SRV_P/I/D`**: Standard PID gains.
*   **`STEER2SRV_FF`**: Feedforward gain. Critical for Ackermann (car-like) steering.
*   **`STEER2SRV_TCONST`**: Time constant (seconds) for the response.

### 2. Speed Derating (`STEER2SRV_DRTFCT`)
At high speeds, a car becomes very sensitive to steering inputs.
*   **Derating:** The autopilot automatically reduces the maximum steering angle as speed increases to prevent roll-overs.
*   **`STEER2SRV_DRTSPD`**: The speed at which derating starts.

## Parameter Breakdown

*   **`STEER2SRV_P`**: Proportional gain (steering stiffness).
*   **`STEER2SRV_DRTMIN`**: Minimum steering angle floor at high speed.

## Integration Guide
*   **Tuning:** Use **AUTOTUNE** in ArduRover to set these gains.
*   **Manual Setup:** Ensure `STEER2SRV_FF` is set correctly so that the wheels turn to the correct angle to achieve the commanded turn rate at cruise speed.

## Developer Notes
*   **Library:** `libraries/APM_Control/AP_SteerController.cpp`.