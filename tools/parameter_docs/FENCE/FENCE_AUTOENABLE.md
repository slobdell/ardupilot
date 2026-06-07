---
layout: parameter
name: FENCE_AUTOENABLE
display_name: Fence Auto-Enable
description: Automated logic for enabling/disabling fences based on takeoff and landing.
default_value: 0
range: 0 3
units: 
group: FENCE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Fence/AC_Fence.cpp
---

# Fence Auto-Enable (FENCE_AUTOENABLE)

## Description
Allows the flight controller to automatically engage the geofence system at specific flight stages, such as after reaching a safe altitude following takeoff.

## Tuning & Behavior
*   **Default Value:** 0 (Always Disabled)
*   **Values:** 
    *   1: AutoEnableOnTakeoff
    *   2: AutoEnableDisableFloorOnLanding
    *   3: AutoEnableOnlyWhenArmed