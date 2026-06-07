---
layout: parameter
name: FENCE_RET_RALLY
display_name: Fence Return to Rally
description: Determines if the vehicle should return to a rally point or the fence return point upon breach (Plane).
default_value: 0
range: 0 1
units: 
group: FENCE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Fence/AC_Fence.cpp
---

# Fence Return to Rally (FENCE_RET_RALLY)

## Description
For ArduPlane, specifies whether a fence breach should trigger a return to the nearest rally point instead of the primary fence return point.
*   **0: Fence Return Point**
*   **1: Nearest Rally Point**