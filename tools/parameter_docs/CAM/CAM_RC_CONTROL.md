---
layout: parameter
name: CAM_RC_CONTROL
display_name: RunCam Control Options
description: Defines the stick gestures used to enter the camera's OSD menu and other automation options.
default_value: 1
range: 0 15
units: 
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_RunCam.cpp#L71
---

# RunCam Control Options (CAM_RC_CONTROL)

## Description
`CAM_RC_CONTROL` defines the "Magic Gestures" used to control your RunCam actions from the transmitter.

It is a bitmask to enable specific control methods:
*   **Bit 0 (1): Roll Right.** Enter the camera menu by holding the Roll stick to the right while disarmed.
*   **Bit 1 (2): Pitch Down.** 
*   **Bit 2 (4): Auto-Record.** Starts recording automatically as soon as the drone is armed.

## Tuning & Behavior
*   **Default:** 1 (Roll Right).
*   **Recommendation:** Enable **Bit 2 (4)** if you want to ensure you always capture your flight footage without having to remember to press a button.