---
alias_target: CAM_TRIGG_DIST
default_value: 0
description: Distance in meters between camera triggers. If this value is non-zero
  then the camera will trigger whenever the position changes by this number of meters
  regardless of what mode the APM is in. Note that this parameter can also be set
  in an auto mission using the DO_SET_CAM_TRIGG_DIST command, allowing you to enable/disable
  the triggering of the camera during the flight.
display_name: Camera trigger distance
group: CAM
investigation_status: alias
layout: parameter
name: CAM2_TRIGG_DIST
range: 0 1000
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera_Params.cpp#L45
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera_Params.h#L21
units: m
visual_asset_id: null
---

# Camera trigger distance

**Note:** This parameter functions identically to [CAM_TRIGG_DIST](../CAM/CAM_TRIGG_DIST.html).
