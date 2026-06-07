---
layout: parameter
name: SERVO_YAW_TYPE
display_name: Yaw Servo Actuator Type
description: Selects between proportional position servos or discrete on/off actuators for the yaw axis.
default_value: 0
range: 0 1
units: 
group: SERVO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/AntennaTracker/Parameters.cpp#L103
---

# Yaw Servo Actuator Type (SERVO_YAW_TYPE)

## Description
`SERVO_YAW_TYPE` defines the control hardware used for an **Antenna Tracker's** horizontal (pan) axis.