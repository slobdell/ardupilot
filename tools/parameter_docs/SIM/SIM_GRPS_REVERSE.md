---
layout: parameter
name: SIM_GRPS_REVERSE
display_name: Gripper Reverse
description: Inverts the open/close direction of the simulated gripper.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Gripper_Servo.cpp#L61
---

# Gripper Reverse (SIM_GRPS_REVERSE)

## Description
`SIM_GRPS_REVERSE` swaps the open and closed states of the virtual jaws.