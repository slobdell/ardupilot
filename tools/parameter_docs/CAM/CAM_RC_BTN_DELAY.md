---
layout: parameter
name: CAM_RC_BTN_DELAY
display_name: RunCam Press Hold Time
description: The duration (in milliseconds) of a virtual button press for RunCam serial control.
default_value: 300
range: 100 1000
units: ms
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_RunCam.cpp#L58
---

# RunCam Press Hold Time (CAM_RC_BTN_DELAY)

## Description
`CAM_RC_BTN_DELAY` defines the duration of each "Click" sent to the camera.

When the autopilot simulates a button press (e.g. to start a recording), it must "hold" that signal for a minimum amount of time for the camera's internal processor to register it. If this value is too low, the camera may ignore commands.

## Tuning & Behavior
*   **Default:** 300 ms.
*   **Significance:** Most RunCam models work best with a 300ms pulse. If your camera is intermittently ignoring start/stop commands, try increasing this to **500ms**.