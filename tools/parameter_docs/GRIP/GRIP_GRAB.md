---
layout: parameter
name: GRIP_GRAB
display_name: Gripper Grab PWM
description: PWM value in microseconds sent to the gripper to initiate grabbing the cargo.
default_value: 1900
range: 1000 2000
units: PWM
group: GRIP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Gripper/AP_Gripper.cpp
---

# Gripper Grab PWM (GRIP_GRAB)

## Description
The PWM signal value that triggers the "Closed" or "Grab" position of the gripper.
