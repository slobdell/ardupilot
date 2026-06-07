---
layout: parameter
name: COMPASS_MOT2
display_name: Compass 2 Motor interference compensation
description: Motor interference compensation for the second compass.
default_value: 0
range: -1000 1000
units: mGauss/A
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Compass 2 Motor interference compensation (COMPASS_MOT2)

## Description
Dynamic magnetic interference compensation for the secondary magnetometer.