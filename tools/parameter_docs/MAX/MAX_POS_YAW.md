---
layout: parameter
name: MAX_POS_YAW
display_name: Max Yaw Position Delta (Blimp)
description: Sets the maximum allowed yaw angle change per update cycle.
default_value: 0.3
range: 0.1 5.0
units: rad/s
group: MAX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Blimp/Parameters.cpp#L249
---

# Max Yaw Position Delta (MAX_POS_YAW)

## Description
`MAX_POS_YAW` limits how fast the blimp's heading target can rotate. This is crucial for avoiding large, oscillating yaw movements in airships with high rotational inertia.