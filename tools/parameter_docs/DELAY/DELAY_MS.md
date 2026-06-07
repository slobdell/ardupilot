---
layout: parameter
name: DELAY_MS
display_name: Sensor Delay (Invalid/Legacy)
description: This parameter appears to be miscategorized. It may refer to VISO_DELAY_MS or CHUTE_DELAY_MS.
default_value: 0
range: 
units: ms
group: DELAY
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_VisualOdom/AP_VisualOdom.cpp
---

# Sensor Delay (DELAY_MS)

## Description
This parameter is not found as a top-level DELAY_MS in the main codebase. It likely refers to a specific sensor delay in a subgroup (e.g., Visual Odometry or Parachute).