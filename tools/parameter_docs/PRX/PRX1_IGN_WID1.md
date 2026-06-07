---
layout: parameter
name: PRX1_IGN_WID1
display_name: Proximity Ignore Width (Sector 1)
description: The total width (in degrees) of the sector to ignore around the ignore angle.
default_value: 0
range: 0 127
units: deg
group: PRX
visual_asset_id: prx_ignore_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Proximity/AP_Proximity_Params.cpp#L46
---

# Proximity Ignore Width (PRX1_IGN_WID1)

## Description
`PRX1_IGN_WID1` defines the size of the "Blind Zone" sector centered on [PRX1_IGN_ANG1](PRX1_IGN_ANG1.html).

If you have a 10-degree wide arm in the sensor's path, you would set the center angle to the arm's position and this width to 10. The autopilot will then ignore any data reported within 5 degrees on either side of the center.

## Tuning & Behavior
*   **Default:** 0.
*   **Safety:** Do not set the width unnecessarily large, as you might hide real obstacles from the avoidance system.