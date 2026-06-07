---
layout: parameter
name: CAM_RC_MDE_DELAY
display_name: RunCam Mode Transition Delay
description: The delay (in milliseconds) enforced when switching between Camera and Video modes.
default_value: 500
range: 0 2000
units: ms
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_RunCam.cpp#L110
---

# RunCam Mode Transition Delay (CAM_RC_MDE_DELAY)

## Description
`CAM_RC_MDE_DELAY` handles the timing of mode switches (e.g., from taking a photo to starting a video). 

Action cameras often take a moment to initialize the storage buffer or change sensor resolutions. This parameter ensures the autopilot waits for the camera to be ready before sending the next command.