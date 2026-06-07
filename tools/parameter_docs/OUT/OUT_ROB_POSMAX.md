---
alias_target: SERVO_ROB_POSMAX
default_value: 4095
description: Position maximum at servo max value. This should be within the position
  control range of the servos, normally 0 to 4095
display_name: Robotis servo position max
group: OUT
investigation_status: alias
layout: parameter
name: OUT_ROB_POSMAX
range: 0 4095
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RobotisServo/AP_RobotisServo.cpp#L125
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RobotisServo/AP_RobotisServo.h#L70
units: ''
visual_asset_id: null
---

# Robotis servo position max

**Note:** This parameter configures instance ROB_POSMAX. It functions identically to [SERVO_ROB_POSMAX](../SERVO/SERVO_ROB_POSMAX.html).
