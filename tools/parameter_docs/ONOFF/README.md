# On/Off Tracker Configuration (ONOFF)

## Overview
The **ONOFF** parameter group configures the behavior of **On/Off** (Bang-Bang) control for the **Antenna Tracker**.

While many trackers use high-precision servos (proportional control), some use simple DC motors or relays that can only be turned Fully On or Fully Off. This system estimates how long to run the motor to achieve the desired angle.

## Key Concepts

### 1. Slew Rates (`ONOFF_..._RATE`)
Defines the speed (deg/s) of the tracker mechanism. Since there is no feedback from the motor itself, the autopilot assumes the tracker moves at exactly this rate.

### 2. Minimum Time (`ONOFF_..._MINT`)
Defines the shortest possible "pulse" or motor activation. This prevents the relays from clicking rapidly (chattering) when only a tiny correction is needed.

## Parameter Breakdown

*   **`ONOFF_YAW_RATE`**: Speed of the yaw rotation.
*   **`ONOFF_PITCH_RATE`**: Speed of the pitch rotation.
*   **`ONOFF_YAW_MINT`**: Minimum activation time for yaw.

## Developer Notes
*   **Library:** `AntennaTracker/Parameters.cpp`.
*   **Context:** Only relevant if `SERVO_YAW_TYPE` or `SERVO_PITCH_TYPE` is set to 1 (On/Off).