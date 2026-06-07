---
layout: parameter
name: AVD_W_DIST_Z
display_name: Distance Warn Z
description: Closest allowed projected vertical distance before W_ACTION is undertaken.
default_value: 300
range: 1 1000
units: m
group: AVD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Avoidance/AP_Avoidance.cpp
---

# Distance Warn Z (AVD_W_DIST_Z)

## Description
Vertical separation threshold for the "Warn" threat level.

## Tuning & Behavior
*   **Default Value:** 300 m
*   **Range:** 1 to 1000 m