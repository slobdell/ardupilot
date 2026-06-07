---
layout: parameter
name: CAM_SERVO_ON
display_name: Camera servo ON PWM value
description: PWM value in microseconds to move servo to when shutter is activated.
default_value: 1300
range: 1000 2000
units: PWM
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera_Params.cpp
---

# Camera servo ON PWM value (CAM_SERVO_ON)

## Description
The PWM value sent to the camera trigger servo when a photo is requested.