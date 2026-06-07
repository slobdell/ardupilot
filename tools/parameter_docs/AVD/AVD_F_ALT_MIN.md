---
layout: parameter
name: AVD_F_ALT_MIN
display_name: ADS-B avoidance minimum altitude
description: Minimum AMSL altitude for ADS-B avoidance. If the vehicle is below this altitude, no avoidance action will take place.
default_value: 0
range: 
units: m
group: AVD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Avoidance/AP_Avoidance.cpp
---

# ADS-B avoidance minimum altitude (AVD_F_ALT_MIN)

## Description
Safety floor for ADS-B avoidance. Avoidance maneuvers are disabled below this altitude to prevent collisions with ground structures or during landing.

## Tuning & Behavior
*   **Default Value:** 0 m (Disabled)
*   **Recommended to be set above the local tree line or building height.**