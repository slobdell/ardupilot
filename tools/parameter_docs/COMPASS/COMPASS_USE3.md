---
layout: parameter
name: COMPASS_USE3
display_name: Compass 3 used for yaw
description: Enable or disable the tertiary compass for determining heading.
default_value: 1
range: 0 1
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Compass 3 used for yaw (COMPASS_USE3)

## Description
Determines if the tertiary compass data is used by the EKF.