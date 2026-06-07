---
layout: parameter
name: FENCE_RET_ALT
display_name: Fence Return Altitude
description: Altitude the vehicle will transit to when a fence breach occurs (Plane).
default_value: 0
range: 0 32767
units: m
group: FENCE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Fence/AC_Fence.cpp
---

# Fence Return Altitude (FENCE_RET_ALT)

## Description
Specifies the safe altitude to maintain while returning from a geofence breach.
*   **Units are in meters.**