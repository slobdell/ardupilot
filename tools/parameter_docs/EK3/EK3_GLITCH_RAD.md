---
layout: parameter
name: EK3_GLITCH_RAD
display_name: GPS glitch radius gate size
description: Controls the maximum radial uncertainty in position before the filter resets to the GPS.
default_value: 25
range: 10 100
units: m
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# GPS glitch radius gate size (EK3_GLITCH_RAD)

## Description
Defines the maximum allowed discrepancy between the predicted and measured GPS position.
