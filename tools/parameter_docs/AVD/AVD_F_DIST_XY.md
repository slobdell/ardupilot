---
layout: parameter
name: AVD_F_DIST_XY
display_name: Distance Fail XY
description: Closest allowed projected horizontal distance before F_ACTION is undertaken.
default_value: 300
range: 1 2000
units: m
group: AVD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Avoidance/AP_Avoidance.cpp
---

# Distance Fail XY (AVD_F_DIST_XY)

## Description
Horizontal separation threshold for the "Fail" threat level.

## Tuning & Behavior
*   **Default Value:** 300 m (Plane), 100 m (Copter)
*   **Range:** 1 to 2000 m