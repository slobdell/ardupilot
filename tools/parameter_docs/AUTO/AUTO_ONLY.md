---
layout: parameter
name: AUTO_ONLY
display_name: Camera Auto Mode Only
description: If enabled, the camera will only be triggered when the vehicle is in an autonomous mode (e.g., AUTO, GUIDED, RTL).
default_value: 0
range: 0 1
units: 
group: AUTO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera.cpp
---

# Camera Auto Mode Only (AUTO_ONLY)

## Description
Restricts camera triggering functionality to autonomous mission modes. This prevents accidental triggers during manual flight or while on the ground in manual modes.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled - Can trigger in any mode)
*   **Setting to 1 ensures camera missions only run during the actual mission legs.**