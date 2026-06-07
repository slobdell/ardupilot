---
layout: parameter
name: CHUTE_SERVO_OFF
display_name: Servo OFF PWM value
description: Parachute Servo PWM value in microseconds when parachute is not released.
default_value: 1100
range: 1000 2000
units: PWM
group: CHUTE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Parachute/AP_Parachute.cpp
---

# Servo OFF PWM value (CHUTE_SERVO_OFF)

## Description
The idle (closed) PWM position for the parachute servo.