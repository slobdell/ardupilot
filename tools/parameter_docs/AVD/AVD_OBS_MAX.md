---
layout: parameter
name: AVD_OBS_MAX
display_name: Maximum number of obstacles to track
description: Maximum number of obstacles to track simultaneously.
default_value: 20
range: 1 50
units: 
group: AVD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Avoidance/AP_Avoidance.cpp
---

# Maximum number of obstacles to track (AVD_OBS_MAX)

## Description
Limits the memory and CPU resources spent on tracking distant ADS-B vehicles.

## Tuning & Behavior
*   **Default Value:** 20
*   **Range:** 1 to 50