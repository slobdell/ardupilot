---
layout: parameter
name: SERVO_VOLZ_RANGE
display_name: Volz Servo Travel Range
description: Sets the angular range (in degrees) that is mapped to the 1000-2000 PWM signal range for Volz servos.
default_value: 200
range: 40 200
units: deg
group: SERVO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Volz_Protocol/AP_Volz_Protocol.cpp#L46
---

# Volz Servo Travel Range (SERVO_VOLZ_RANGE)

## Description
`SERVO_VOLZ_RANGE` is a scaling parameter for high-end **Volz digital servos**.

These servos use a digital protocol but can be commanded via a virtual PWM signal from the autopilot. This parameter defines how many degrees of physical rotation correspond to the standard 1000-2000µs PWM range.

*   **200 (Default):** Maps $\pm$ 100 degrees of rotation.
*   **40:** Maps $\pm$ 20 degrees. This provides much higher "Resolution" (finer movements) if your control surface doesn't need full travel.

## Tuning & Behavior
*   **Default:** 200.
*   **Significance:** If you decrease this value, the servo will move more slowly and precisely for the same amount of stick movement. 
*   **Requirement:** Only relevant if you are using the Volz protocol (`SERIALx_PROTOCOL` = 20) and have Volz actuators installed.