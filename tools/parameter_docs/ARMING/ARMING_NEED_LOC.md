---
layout: parameter
name: ARMING_NEED_LOC
display_name: Require vehicle location
description: Require that the vehicle have an absolute position before it arms. This can help ensure that the vehicle can Return To Launch.
default_value: 0
range: 0 1
units: 
group: ARMING
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Arming/AP_Arming.cpp
---

# Require vehicle location (ARMING_NEED_LOC)

## Description
Strict requirement for a valid 3D GPS fix (or other absolute position) before arming is permitted.

## Tuning & Behavior
*   **Default Value:** 0 (Not required for most vehicles; Copter often defaults to 1 for safety)
*   **Setting to 1 ensures the vehicle has a known "Home" position for failsafe RTL.**