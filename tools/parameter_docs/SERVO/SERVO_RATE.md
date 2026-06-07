---
layout: parameter
name: SERVO_RATE
display_name: Servo Output Rate
description: The default update frequency (in Hz) for all PWM servo outputs.
default_value: 50
range: 50 400
units: Hz
group: SERVO
visual_asset_id: rc_speed_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SRV_Channel/SRV_Channels.cpp#L100
---

# Servo Output Rate (SERVO_RATE)

## Description
`SERVO_RATE` sets the "Frame Rate" for your servos.

*   **50Hz (Default):** Standard for analog servos and fixed-wing aircraft.
*   **400Hz:** High speed for digital servos and multicopter ESCs using PWM.

**Warning:** Sending 400Hz to an analog servo will cause it to overheat and burn out.

## Tuning & Behavior
*   **Default Value:** 50 Hz.
*   **Recommendation:**
    *   **Plane:** 50 Hz.
    *   **Copter:** 400 Hz (if using PWM).
    *   **DShot:** Ignored (DShot runs at its own protocol speed).