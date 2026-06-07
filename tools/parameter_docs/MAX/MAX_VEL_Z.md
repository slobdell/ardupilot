---
layout: parameter
name: MAX_VEL_Z
display_name: Max Vertical Velocity Delta (Blimp)
description: Sets the maximum allowed change in vertical velocity (vertical acceleration limit).
default_value: 0.5
range: 0.1 5.0
units: m/s^2
group: MAX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Blimp/Parameters.cpp#L261
---

# Max Vertical Velocity Delta (MAX_VEL_Z)

## Description
`MAX_VEL_Z` limits vertical acceleration. It ensures that the blimp's transition between climbing and descending is handled smoothly by the buoyancy and motor control logic.