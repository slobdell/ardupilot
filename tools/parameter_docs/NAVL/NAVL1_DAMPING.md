---
layout: parameter
name: NAVL1_DAMPING
display_name: L1 Navigation Damping
description: Sets the damping ratio for the L1 navigation loop.
default_value: 0.75
range: 0.6 1.0
units: 
group: NAVL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_L1_Control/AP_L1_Control.cpp#L25
---

# L1 Navigation Damping (NAVL1_DAMPING)

## Description
`NAVL1_DAMPING` prevents the aircraft from overshooting the path when it tries to intercept a line.

It defines the "Sharpness" of the turn into the path. A value of **0.75** is standard for most aircraft. If the plane consistently "misses" the line and has to turn back to find it, increasing this value can help.