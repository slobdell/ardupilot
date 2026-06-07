---
layout: parameter
name: PRX1_IGN_ANG1
display_name: Proximity Ignore Angle (Sector 1)
description: The center angle of a sector to ignore for obstacle avoidance.
default_value: 0
range: 0 360
units: deg
group: PRX
visual_asset_id: prx_ignore_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Proximity/AP_Proximity_Params.cpp#L38
---

# Proximity Ignore Angle (PRX1_IGN_ANG1)

## Description
`PRX1_IGN_ANG1` (and ANG2-ANG4) defines the center of a "Blind Zone" for your proximity sensor. 

This is used to prevent the drone from reacting to its own structure (like landing gear, arms, or GPS masts) that might be in the sensor's line of sight. By telling the autopilot to "ignore" a specific angle, you avoid false obstacle detections.

*   **Units:** Degrees (0 to 360).
*   **Reference:** 0 is forward, 90 is right, 180 is back, 270 is left.

## Tuning & Behavior
*   **Default:** 0.
*   **Integration:** Use this in combination with [PRX1_IGN_WID1](PRX1_IGN_WID1.html) to define the width of the excluded sector.