---
layout: parameter
name: MOT_YAW_SV_ANGLE
display_name: Tricopter Yaw Servo Max Angle
description: The maximum mechanical lean angle (in degrees) of the tail servo on a Tricopter.
default_value: 30
range: 5 80
units: deg
group: MOT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L163
---

# Tricopter Yaw Servo Max Angle (MOT_YAW_SV_ANGLE)

## Description
`MOT_YAW_SV_ANGLE` defines the mechanical limit of the tilt mechanism on your Tricopter's tail motor.

Tricopters use a single tilting motor for yaw control. This parameter tells the autopilot how many degrees that motor can physically tilt to the left or right. This is used to calibrate the relationship between the requested "Yaw Force" and the physical servo movement.

## Tuning & Behavior
*   **Default:** 30 degrees.
*   **Measurement:** Tilt your tail servo to its maximum physical limit. Use a protractor to measure the angle from the vertical. Enter that value here.
*   **Significance:** If this value is incorrect, your Tricopter's yaw gains will be off, leading to sluggish or oscillating yaw behavior.