---
alias_target: SERVO_FTW_MASK
default_value: 0
description: This is a bitmask of motors that are tiltable in a tiltrotor (or tiltwing).
  The mask is in terms of the standard motor order for the frame type.
display_name: Tiltrotor mask
group: OUT
investigation_status: alias
layout: parameter
name: OUT_FTW_MASK
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/tiltrotor.cpp#L20
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/tiltrotor.h#L49
units: null
visual_asset_id: null
---

# Tiltrotor mask

**Note:** This parameter configures instance FTW_MASK. It functions identically to [SERVO_FTW_MASK](../SERVO/SERVO_FTW_MASK.html).
