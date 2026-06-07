---
layout: parameter
name: FOLL_DIST_MAX
display_name: Follow Max Distance
description: The maximum allowed distance (in meters) from the target before the follow mode is aborted for safety.
default_value: 100
range: 1 1000
units: m
group: FOLL
visual_asset_id: follow_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Follow/AP_Follow.cpp#L104
---

# Follow Max Distance (FOLL_DIST_MAX)

## Description
`FOLL_DIST_MAX` is the "Leash" length.

If the target vehicle speeds away and the distance between your drone and the target exceeds this value, the autopilot will stop chasing and switch to a safe mode (usually Loiter). This prevents the drone from blindly flying over the horizon if it loses its connection to the target.