# Throttle Configuration (THR)

## Overview
The **THR** parameter group configures the global **Throttle** behaviors for the vehicle. It defines safety limits, deadzones, and automated management logic.

## Key Concepts

### 1. Failsafe (`THR_FAILSAFE`)
One of the most important safety settings. If the signal from the RC receiver drops below a certain threshold (`THR_FS_VALUE`), the autopilot triggers a Radio Failsafe.

### 2. Limits (`THR_MIN`, `THR_MAX`)
Defines the allowable range of motor power.
*   **`THR_MIN`**: The lowest throttle level allowed in flight (ensures motors don't stop).
*   **`THR_MAX`**: The absolute ceiling for throttle output.

### 3. Slew Rate (`THR_SLEWRATE`)
Limits how fast the throttle can change (percentage per second).
*   **Purpose:** Prevents mechanical stress and battery current spikes from instantaneous throttle jumps.

## Developer Notes
*   **Library:** `libraries/AP_Motors`, `libraries/AP_Vehicle`.
*   **Context:** `THR_MIN` is critical for ArduPlane to ensure the motor stays running during an auto-landing or glide if an ICE engine is used.