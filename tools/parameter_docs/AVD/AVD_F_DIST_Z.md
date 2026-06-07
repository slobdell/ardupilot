---
layout: parameter
name: AVD_F_DIST_Z
display_name: Distance Fail Z
description: Closest allowed projected vertical distance before F_ACTION is undertaken.
default_value: 100
range: 1 500
units: m
group: AVD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Avoidance/AP_Avoidance.cpp
---

# Distance Fail Z (AVD_F_DIST_Z)

## Description
Vertical separation threshold for the "Fail" threat level.

## Tuning & Behavior
*   **Default Value:** 100 m
*   **Range:** 1 to 500 m