---
layout: parameter
name: COMPASS_SCALE
display_name: Compass scale factor
description: Scaling factor for the compass to compensate for sensor scaling errors.
default_value: 0
range: 0 1.3
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Compass scale factor (COMPASS_SCALE)

## Description
A sensitivity adjustment for the magnetometer. If set to 0, no scaling is applied.
