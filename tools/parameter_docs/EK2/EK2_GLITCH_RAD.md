---
layout: parameter
name: EK2_GLITCH_RAD
display_name: GPS glitch radius gate size
description: Controls the maximum radial uncertainty in position between the filter prediction and the GPS measurement before the filter resets to the GPS.
default_value: 25
range: 10 100
units: m
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# GPS glitch radius gate size (EK2_GLITCH_RAD)

## Description
Defines the maximum allowed distance "jump" in GPS position before the EKF flags it as a glitch.