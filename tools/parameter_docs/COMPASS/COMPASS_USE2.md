---
layout: parameter
name: COMPASS_USE2
display_name: Compass 2 used for yaw
description: Enable or disable the secondary compass for determining heading.
default_value: 1
range: 0 1
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Compass 2 used for yaw (COMPASS_USE2)

## Description
Determines if the secondary compass data is used by the EKF.