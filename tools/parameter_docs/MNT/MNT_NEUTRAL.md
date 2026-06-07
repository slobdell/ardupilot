---
layout: parameter
name: MNT_NEUTRAL
display_name: Mount Neutral Position
description: The 3-axis position (Roll, Pitch, Yaw) the gimbal moves to when in neutral mode.
default_value: 0
range: -180 180
units: deg
group: MNT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L136
---

# Mount Neutral Position (MNT_NEUTRAL)

## Description
`MNT_NEUTRAL` defines the "Center" position of the gimbal. 

This is used when the gimbal mode is set to **Neutral**. Typically, this is set to (0, 0, 0) so that the camera points straight ahead along the drone's longitudinal axis. 

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** If your gimbal is mounted slightly crooked, you can use these parameters to "Trim" the neutral position so that the camera is perfectly centered when the autopilot is in Neutral mode.