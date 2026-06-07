---
layout: parameter
name: COMPASS_AUTODEC
display_name: Auto Declination
description: Enable or disable the automatic calculation of the declination based on GPS location.
default_value: 1
range: 0 1
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Auto Declination (COMPASS_AUTODEC)

## Description
Allows ArduPilot to automatically look up the correct magnetic declination using an internal world magnetic model and your current GPS coordinates.
