---
layout: parameter
name: CAM_DURATION
display_name: Camera shutter duration
description: Duration in seconds that the camera shutter is held open.
default_value: 0.1
range: 0 5
units: s
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera_Params.cpp
---

# Camera shutter duration (CAM_DURATION)

## Description
Duration of the trigger pulse sent to the camera. For most digital cameras, a short pulse (0.1s to 0.5s) is sufficient to trigger a capture.