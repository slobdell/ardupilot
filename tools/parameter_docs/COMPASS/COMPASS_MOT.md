---
layout: parameter
name: COMPASS_MOT
display_name: Motor interference compensation (X, Y, Z)
description: Multiplied by current/throttle and added to compass values to compensate for motor interference.
default_value: 0
range: -1000 1000
units: mGauss/A
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Motor interference compensation (COMPASS_MOT)

## Description
Scaling factors for dynamic magnetic interference. These values determine how much the compass heading should be adjusted based on the current power level.
