---
layout: parameter
name: H_GYR_GAIN
display_name: External Gyro Gain
description: PWM value (offset from 1000) sent to an external tail gyro.
default_value: 0
range: 0 1000
units: PWM
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_Single.cpp
---

# External Gyro Gain (H_GYR_GAIN)

## Description
Specifies the gain value sent to an external tail-lock gyroscope.
*   **Only used if H_TAIL_TYPE is set to 1 (Servo with External Gyro).**