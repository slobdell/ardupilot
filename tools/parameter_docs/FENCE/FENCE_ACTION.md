---
layout: parameter
name: FENCE_ACTION
display_name: Fence Action
description: Specifies the action taken when a geofence boundary is breached.
default_value: 1
range: 0 5
units: 
group: FENCE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Fence/AC_Fence.cpp
---

# Fence Action (FENCE_ACTION)

## Description
Defines the automatic flight behavior triggered by a fence breach.

## Tuning & Behavior
*   **Default Value:** 1 (RTL or Land)
*   **Values:** 0:Report Only, 1:RTL or Land, 2:Always Land, 3:SmartRTL, 4:Brake or Land
*   **Note: Plane uses 1:RTL, 6:Guided.**
