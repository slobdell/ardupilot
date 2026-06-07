---
layout: parameter
name: MAX_VEL_XY
display_name: Max Horizontal Velocity Delta (Blimp)
description: Sets the maximum allowed change in horizontal velocity (acceleration limit) per update.
default_value: 0.5
range: 0.1 5.0
units: m/s^2
group: MAX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Blimp/Parameters.cpp#L255
---

# Max Horizontal Velocity Delta (MAX_VEL_XY)

## Description
`MAX_VEL_XY` acts as an acceleration limit for the blimp's horizontal flight. It prevents the autopilot from demanding sudden bursts of speed that would cause the blimp to pitch or swing violently.