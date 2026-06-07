---
layout: parameter
name: MNT1_DEFLT_MODE
display_name: Mount Default Mode (Instance 1)
description: Defines the gimbal behavior on startup or when control is returned to the autopilot.
default_value: 3
range: 0 6
units: 
group: MNT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L23
---

# Mount Default Mode (MNT1_DEFLT_MODE)

## Description
`MNT1_DEFLT_MODE` sets the fallback behavior for the gimbal. It determines where the camera points when the drone first powers on, or when an autonomous mission ends and returns control to the pilot.

*   **0: Retracted.** Gimbal moves to its stowed position.
*   **1: Neutral.** Gimbal points straight forward.
*   **2: MAVLink.** Waits for a command from the GCS.
*   **3: RC Targeting.** (Default). The gimbal follows the position of the knobs/sliders on your transmitter.
*   **4: GPS Point.** Points at a specific location on the map.

## Tuning & Behavior
*   **Default:** 3 (RC Targeting).
*   **Recommendation:** Set to **3** if you want manual control of the camera tilt during flight. Set to **6 (Home Location)** if you want the camera to automatically track the takeoff point.