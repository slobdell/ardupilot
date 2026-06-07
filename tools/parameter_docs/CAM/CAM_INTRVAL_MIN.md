---
layout: parameter
name: CAM_INTRVAL_MIN
display_name: Camera minimum time interval
description: Minimum time in seconds between consecutive photos.
default_value: 0
range: 0 10
units: s
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera_Params.cpp
---

# Camera minimum time interval (CAM_INTRVAL_MIN)

## Description
A rate-limiting safety feature. Photos will not be triggered faster than this interval, even if other trigger conditions (like CAM_TRIGG_DIST) are met. This allows the camera hardware time to save images.