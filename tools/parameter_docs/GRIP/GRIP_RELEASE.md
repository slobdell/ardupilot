---
layout: parameter
name: GRIP_RELEASE
display_name: Gripper Release PWM
description: PWM value in microseconds sent to the gripper to release the cargo.
default_value: 1100
range: 1000 2000
units: PWM
group: GRIP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Gripper/AP_Gripper.cpp
---

# Gripper Release PWM (GRIP_RELEASE)

## Description
The PWM signal value that triggers the "Open" or "Release" position of the gripper.