---
layout: parameter
name: SERVO_ROB_POSMAX
display_name: Robotis Servo Position Max
description: The maximum raw position value (0-4095) for Robotis (Dynamixel) servos.
default_value: 4095
range: 0 4095
units: 
group: SERVO
visual_asset_id: servo_range_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RobotisServo/AP_RobotisServo.cpp#L100
---

# Robotis Servo Position Max (SERVO_ROB_POSMAX)

## Description
`SERVO_ROB_POSMAX` sets the upper travel limit for **Robotis** servos.

## Tuning & Behavior
*   **Default Value:** 4095.
*   **Recommendation:** Reduce this if the servo hits a hard stop before reaching the full 360-degree (or configured) range.
