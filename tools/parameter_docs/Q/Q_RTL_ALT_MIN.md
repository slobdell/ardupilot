---
layout: parameter
name: Q_RTL_ALT_MIN
display_name: QuadPlane RTL Minimum Altitude
description: The minimum altitude (in meters) the vehicle should maintain during the approach phase of an RTL.
default_value: 0
range: 0 50
units: m
group: Q
visual_asset_id: vtol_land_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane RTL Minimum Altitude (Q_RTL_ALT_MIN)

## Description
`Q_RTL_ALT_MIN` ensures the plane doesn't descend too early.

If `RTL_ALT` (the cruise altitude) is very high, the plane might try to descend steeply to reach `Q_RTL_ALT` (the landing altitude). This parameter puts a floor on that descent so the plane stays safely above the ground until it is close to home.