---
layout: parameter
name: PUP_NG_JERK_LIM
display_name: Maximum normal load factor rate of change during pullup
description: The maximum rate of change of normal load factor (Jerk) allowed during the pullup maneuver.
default_value: 5.0
range: 1.0 10.0
units: 1/s
group: PUP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/pullup.cpp#L38
---

# PUP_NG_JERK_LIM: Maximum normal load factor rate of change during pullup

## Description
The maximum rate of change of normal load factor (Jerk) allowed during the pullup maneuver.

## Values
- **Range:** 1.0 to 10.0
- **Units:** 1/s
- **Default:** 5.0

## Description
This parameter controls how smoothly the G-force is applied.

- **Function:** Instead of snapping instantly from 1G to 4G (which could snap the wing spar), this parameter ramps the G-load up gradually.
- **Physics:** It limits the "Jerk" (the derivative of acceleration).
- **Effect:** A lower value makes the onset of the pull-up smoother but takes longer to reach the maximum turn rate, requiring more altitude. A higher value initiates the turn faster but puts a sudden shock load on the airframe.

