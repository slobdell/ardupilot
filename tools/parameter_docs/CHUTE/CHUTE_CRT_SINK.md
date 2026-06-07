---
layout: parameter
name: CHUTE_CRT_SINK
display_name: Critical sink speed rate
description: Release parachute when critical sink rate is reached.
default_value: 0
range: 0 15
units: m/s
group: CHUTE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Parachute/AP_Parachute.cpp
---

# Critical sink speed rate (CHUTE_CRT_SINK)

## Description
Automatic trigger threshold based on descent rate. If the vehicle is falling faster than this value for more than one second, the parachute will automatically deploy.
*   **0 disables automatic sink-rate triggering.**