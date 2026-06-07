---
layout: parameter
name: CAM_RC_BT_DELAY
display_name: RunCam Button Delay
description: The delay (in milliseconds) between simulated button presses in the camera's OSD menu.
default_value: 300
range: 0 1000
units: ms
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_RunCam.cpp#L100
---

# RunCam Button Delay (CAM_RC_BT_DELAY)

## Description
`CAM_RC_BT_DELAY` determines the navigation speed of the RunCam OSD menu.

When you use your transmitter sticks to move through the camera's settings menu, the autopilot sends "Virtual Button" pulses. This delay ensures that the pulses aren't so fast that the camera skips menu items or becomes unresponsive.

## Tuning & Behavior
*   **Default:** 300 ms.
*   **Recommendation:** Leave at **300**. If the menu feels sluggish, you can try reducing to **200**.