---
layout: parameter
name: CAM_FEEDBAK_PIN
display_name: Camera feedback pin
description: Pin number to use for accurate camera feedback messages (Hot Shoe).
default_value: -1
range: 
units: 
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera_Params.cpp
---

# Camera feedback pin (CAM_FEEDBAK_PIN)

## Description
Specifies the hardware pin connected to the camera's hot shoe or flash feedback port. This allows ArduPilot to log the *exact* moment the shutter opened, rather than just the moment the command was sent.