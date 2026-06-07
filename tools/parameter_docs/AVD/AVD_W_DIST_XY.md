---
layout: parameter
name: AVD_W_DIST_XY
display_name: Distance Warn XY
description: Closest allowed projected horizontal distance before W_ACTION is undertaken.
default_value: 1000
range: 1 5000
units: m
group: AVD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Avoidance/AP_Avoidance.cpp
---

# Distance Warn XY (AVD_W_DIST_XY)

## Description
Horizontal separation threshold for the "Warn" threat level.

## Tuning & Behavior
*   **Default Value:** 1000 m (Plane), 300 m (Copter)
*   **Range:** 1 to 5000 m