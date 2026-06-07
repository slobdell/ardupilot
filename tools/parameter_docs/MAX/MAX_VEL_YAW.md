---
layout: parameter
name: MAX_VEL_YAW
display_name: Max Yaw Velocity Delta (Blimp)
description: Sets the maximum allowed change in yaw rate (rotational acceleration limit).
default_value: 0.3
range: 0.1 5.0
units: rad/s^2
group: MAX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Blimp/Parameters.cpp#L267
---

# Max Yaw Velocity Delta (MAX_VEL_YAW)

## Description
`MAX_VEL_YAW` limits the rotational acceleration of the blimp. This prevents the propulsion system from trying to snap the blimp's heading too aggressively, which could damage the frame or motors.