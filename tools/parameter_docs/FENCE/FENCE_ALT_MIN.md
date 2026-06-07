---
layout: parameter
name: FENCE_ALT_MIN
display_name: Fence Minimum Altitude
description: Minimum altitude (Floor) allowed before geofence triggers.
default_value: -10
range: -100 100
units: m
group: FENCE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Fence/AC_Fence.cpp
---

# Fence Minimum Altitude (FENCE_ALT_MIN)

## Description
The "Floor" of the geofence. Useful for preventing underwater vehicles from diving too deep or keeping aircraft above a certain height.