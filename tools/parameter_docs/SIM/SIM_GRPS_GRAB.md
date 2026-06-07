---
layout: parameter
name: SIM_GRPS_GRAB
display_name: Gripper Grab PWM
description: The PWM value (in microseconds) that causes the gripper to grab cargo.
default_value: 1100
range: 1000 2000
units: PWM
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Gripper_Servo.cpp#L46
---

# Gripper Grab PWM (SIM_GRPS_GRAB)

## Description
`SIM_GRPS_GRAB` sets the "Closed" position for the virtual gripper.