---
layout: parameter
name: FENCE_ALT_MAX
display_name: Fence Maximum Altitude
description: Maximum altitude allowed before geofence triggers.
default_value: 100
range: 10 1000
units: m
group: FENCE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Fence/AC_Fence.cpp
---

# Fence Maximum Altitude (FENCE_ALT_MAX)

## Description
The "Ceiling" of the geofence. If the vehicle flies higher than this altitude (relative to Home), the fence action will be triggered.
