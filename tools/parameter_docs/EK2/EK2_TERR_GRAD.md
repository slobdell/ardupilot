---
layout: parameter
name: EK2_TERR_GRAD
display_name: Maximum terrain gradient
description: Specifies the maximum gradient of the terrain below the vehicle assumed when estimating terrain height.
default_value: 0.1
range: 0 0.2
units: 
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Maximum terrain gradient (EK2_TERR_GRAD)

## Description
Assumption about the maximum steepness of the ground, used for terrain height estimation.