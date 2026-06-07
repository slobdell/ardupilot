---
alias_target: BATT_ESC_MASK
default_value: 0
description: This is a bitmask of motors that are tiltable in a tiltrotor (or tiltwing).
  The mask is in terms of the standard motor order for the frame type.
display_name: Tiltrotor mask
group: BATTC
investigation_status: alias
layout: parameter
name: BATTC_ESC_MASK
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/tiltrotor.cpp#L20
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/tiltrotor.h#L49
units: null
visual_asset_id: null
---

# Tiltrotor mask

**Note:** This parameter configures Battery Monitor C. It functions identically to [BATT_ESC_MASK](../BATT/BATT_ESC_MASK.html).
