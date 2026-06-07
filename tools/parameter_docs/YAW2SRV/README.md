# Yaw-to-Servo Configuration (YAW2SRV)

## Overview
The **YAW2SRV** parameter group configures the **Yaw Damping** and **Ground Steering** PID gains for **ArduPlane**.

## Key Concepts

### 1. Yaw Damping (`YAW2SRV_DAMP`)
Prevents the tail of the plane from "wagging" (Dutch Roll) in turbulence.
*   **Action:** Automatically deflects the rudder to oppose sudden uncommanded yaw movements.

### 2. Side-Slip Correction (`YAW2SRV_SLIP`)
Automatically applies rudder during a turn to ensure the ball is centered (coordinated turn), preventing the tail from slipping or skidding.

## Developer Notes
*   **Library:** `libraries/APM_Control/AP_YawController.cpp`.
*   **Context:** Only relevant for **ArduPlane**.