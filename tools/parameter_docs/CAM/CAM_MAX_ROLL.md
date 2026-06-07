---
layout: parameter
name: CAM_MAX_ROLL
display_name: Maximum photo roll angle
description: Postpone shooting if roll is greater than this limit.
default_value: 0
range: 0 180
units: deg
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera.cpp
---

# Maximum photo roll angle (CAM_MAX_ROLL)

## Description
A quality-control feature that prevents photos from being taken during high-bank maneuvers, ensuring images are relatively level with the ground.
*   **0 disables the check.**