---
layout: parameter
name: MNT1_LEAD_PTCH
display_name: Mount Pitch Lead Time
description: Latency compensation for gimbal servos on the pitch axis.
default_value: 0
range: 0 0.2
units: s
group: MNT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L154
---

# Mount Pitch Lead Time (MNT1_LEAD_PTCH)

## Description
`MNT1_LEAD_PTCH` compensates for the "Lag" in your gimbal servos. 

When the drone pitches forward quickly, there is a small delay before the servo actually moves to counteract it. This can result in the horizon tilting momentarily in your video. This parameter tells the autopilot to "Predict" where the vehicle is going based on its current rotation speed and command the servo slightly ahead of time.

## Tuning & Behavior
*   **Default:** 0.
*   **Recommendation:** Increase in small steps (e.g. **0.01s** or **0.02s**). 
*   **Optimal Setting:** The horizon should stay perfectly level even during fast pitch maneuvers.
*   **Warning:** If you set this too high, the gimbal will "Overshoot" or vibrate during fast movements.