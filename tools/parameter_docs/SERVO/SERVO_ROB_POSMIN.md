---
layout: parameter
name: SERVO_ROB_POSMIN
display_name: Robotis Servo Position Min
description: The minimum raw position value (0-4095) for Robotis (Dynamixel) servos.
default_value: 0
range: 0 4095
units: 
group: SERVO
visual_asset_id: servo_range_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RobotisServo/AP_RobotisServo.cpp#L100
---

# Robotis Servo Position Min (SERVO_ROB_POSMIN)

## Description
`SERVO_ROB_POSMIN` sets the lower travel limit for **Robotis Dynamixel** smart servos.

Unlike standard PWM servos (which use 1000-2000µs), Robotis servos use a digital position value, typically 0 to 4095 for a 12-bit resolution.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set to the mechanical limit of your actuator to prevent binding.
