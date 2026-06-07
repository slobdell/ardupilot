# Wheel Encoder Configuration (WENC)

## Overview
The **WENC** parameter group configures the **Wheel Encoders**. These sensors measure the rotation of the vehicle's wheels (or tracks) to provide an accurate estimate of ground velocity and distance traveled.

Wheel encoders are the primary method for high-precision navigation in GPS-denied environments for ground rovers.

## Key Concepts

### 1. Encoder Types (`WENCn_TYPE`)
ArduPilot supports up to 2 wheel encoder instances.
*   **1 (Quadrature):** Uses two digital pins (A and B) to detect both speed and direction.
*   **2 (Single Pin):** Uses one pin to detect speed (cannot detect reverse automatically).

### 2. Resolution (`WENCn_CPR`)
Defines how many pulses the encoder generates for one full rotation of the motor or wheel.
*   **Calculation:** `Pulses_per_revolution * Gear_Ratio`.

### 3. Physical Dimensions (`WENCn_RADIUS`)
The autopilot needs to know the radius (meters) of the wheel to convert "rotations" into "meters traveled."

## Parameter Breakdown

*   **`WENC1_TYPE`**: Driver selection.
*   **`WENC1_PINA` / `PINB`**: GPIO pin assignments.
*   **`WENC1_POS_X/Y/Z`**: Physical offset of the wheel from the vehicle center.

## Integration Guide
1.  **Hardware:** Mount encoders to the driven wheels.
2.  **Enable:** Set `WENC1_TYPE = 1`.
3.  **Calibrate:** Set the `CPR` and `RADIUS` accurately.
4.  **Verify:** Push the rover forward 10 meters and verify the GCS reports exactly 10.0m traveled.

## Developer Notes
*   **Library:** `libraries/AP_WheelEncoder`.
*   **EKF Fusion:** Wheel encoder data is fused into `AP_NavEKF3` to provide a "dead-reckoning" solution when GPS is lost.