# Pitch Controller Configuration (PTCH)

## Overview
The **PTCH** parameter group (often appearing as `PTCH_` or `PTCH2SRV_`) configures the **Pitch Attitude Controller** for **ArduPlane**.

This library is responsible for maintaining the requested pitch angle (e.g., "Nose up 5 degrees") and rotation rates of the aircraft by driving the elevator servos.

## Key Concepts

### 1. Pitch-to-Servo (`PTCH2SRV_...`)
This is the primary PID controller for fixed-wing pitch.
*   **`PTCH2SRV_P/I/D`**: Standard PID gains.
*   **`PTCH2SRV_TCONST`**: The time constant (seconds) for the pitch response. Lower values make the plane more responsive but require higher gains.

### 2. Rate Limits (`PTCH2SRV_RMAX_UP / DN`)
Defines the maximum physical rotation rate (deg/s) of the airframe. This prevents the autopilot from requesting a maneuver so sharp that it stalls the wing or damages the structure.

### 3. Trim (`PTCH_TRIM_DEG`)
Allows for a software-defined pitch offset. If the plane requires a few degrees of up-elevator to fly level at cruise speed, you can enter that offset here to avoid "fighting" the PID integrator.

## Parameter Breakdown

*   **`PTCH2SRV_P`**: Proportional gain (immediate elevator response).
*   **`PTCH2SRV_TCONST`**: Speed of response (typically 0.4s to 0.7s).
*   **`PTCH2SRV_RLL`**: Pitch compensation in turns (automatically adds up-elevator when banking to maintain altitude).

## Integration Guide
*   **Tuning:** Use **AUTOTUNE** in ArduPlane to set these gains. It is much safer and more accurate than manual tuning for fixed-wing aircraft.

## Developer Notes
*   **Library:** `libraries/APM_Control/AP_PitchController.cpp`.