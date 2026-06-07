# Steering Gain Configuration (STR)

## Overview
The **STR** parameter group (often appearing as `ATC_STR_` in newer versions) provides the core tuning for the **Lateral Steering Controller** in ArduRover.

## Key Concepts

### 1. Steering Limits
*   **`STR_RAT_MAX`**: Maximum rotation rate (deg/s) the vehicle is allowed to request during a turn.
*   **`STR_ACC_MAX`**: Maximum lateral acceleration (m/s²) allowed. This is critical for preventing rovers from tipping over in high-speed sharp turns.

### 2. Throttle-to-Steering Mix (`STR_THR_MIX`)
Used on **Skid-Steer** vehicles (tracked or differential drive).
*   **Function:** Defines how much throttle is reduced when turning. This ensures the vehicle has enough power to pivot without stalling the motors.

## Developer Notes
*   **Library:** `libraries/AR_AttitudeControl`.
*   **See Also:** [STEER2SRV](../STEER2SRV/README.md) for related servo gains.