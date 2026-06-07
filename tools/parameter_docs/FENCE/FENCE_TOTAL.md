---
layout: parameter
name: FENCE_TOTAL
display_name: Fence polygon point total
description: Number of polygon points saved in the system.
default_value: 0
range: 1 20
units: 
group: FENCE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Fence/AC_Fence.cpp
---

# Fence polygon point total (FENCE_TOTAL)

## Description
Reports the total number of vertices (points) currently loaded for the polygon fence.
*   **Do not update this value manually.**