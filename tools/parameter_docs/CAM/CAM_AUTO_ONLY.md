---
layout: parameter
name: CAM_AUTO_ONLY
display_name: Distance-triggering in AUTO mode only
description: When enabled, triggering by distance is done in AUTO mode only.
default_value: 0
range: 0 1
units: 
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera.cpp
---

# Distance-triggering in AUTO mode only (CAM_AUTO_ONLY)

## Description
Restricts the CAM_TRIGG_DIST functionality to autonomous modes.
