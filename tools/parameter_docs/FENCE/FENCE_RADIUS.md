---
layout: parameter
name: FENCE_RADIUS
display_name: Circular Fence Radius
description: Radius of the circular fence centered on Home.
default_value: 300
range: 30 10000
units: m
group: FENCE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Fence/AC_Fence.cpp
---

# Circular Fence Radius (FENCE_RADIUS)

## Description
Defines the maximum horizontal distance from the Home point allowed before a fence breach occurs.
*   **Requires Bit 1 to be set in FENCE_TYPE.**
