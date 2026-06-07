---
layout: parameter
name: SIM_GRPS_RELEASE
display_name: Gripper Release PWM
description: The PWM value (in microseconds) that causes the gripper to release cargo.
default_value: 1900
range: 1000 2000
units: PWM
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Gripper_Servo.cpp#L54
---

# Gripper Release PWM (SIM_GRPS_RELEASE)

## Description
`SIM_GRPS_RELEASE` sets the "Open" position for the virtual gripper.