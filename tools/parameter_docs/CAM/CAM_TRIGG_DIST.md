---
layout: parameter
name: CAM_TRIGG_DIST
display_name: Camera trigger distance
description: Distance in meters between camera triggers. If non-zero, the camera triggers whenever the position changes by this amount.
default_value: 0
range: 0 1000
units: m
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera_Params.cpp
---

# Camera trigger distance (CAM_TRIGG_DIST)

## Description
Automates aerial photography by triggering the camera every time the aircraft travels a specified distance.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Useful for mapping missions to ensure consistent overlap between photos.**