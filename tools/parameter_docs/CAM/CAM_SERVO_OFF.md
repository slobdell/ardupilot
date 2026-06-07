---
layout: parameter
name: CAM_SERVO_OFF
display_name: Camera servo OFF PWM value
description: PWM value in microseconds to move servo to when shutter is deactivated.
default_value: 1100
range: 1000 2000
units: PWM
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera_Params.cpp
---

# Camera servo OFF PWM value (CAM_SERVO_OFF)

## Description
The default (idle) PWM value for the camera trigger servo.