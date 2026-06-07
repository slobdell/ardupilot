---
layout: parameter
name: CHUTE_SERVO_ON
display_name: Parachute Servo ON PWM value
description: PWM value in microseconds to move servo to when parachute is released.
default_value: 1300
range: 1000 2000
units: PWM
group: CHUTE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Parachute/AP_Parachute.cpp
---

# Parachute Servo ON PWM value (CHUTE_SERVO_ON)

## Description
The active (release) PWM position for the parachute servo.