---
layout: parameter
name: CAM_RELAY_ON
display_name: Camera relay ON value
description: Sets whether the relay goes high (1) or low (0) when it triggers.
default_value: 1
range: 0 1
units: 
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera_Params.cpp
---

# Camera relay ON value (CAM_RELAY_ON)

## Description
Configures the logic level for relay-based camera triggering.