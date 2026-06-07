---
alias_target: ACRO_Y_RATE
default_value: 90
description: The maximum yaw rate at full stick deflection in QACRO mode
display_name: QACRO mode yaw rate
group: Q
investigation_status: alias
layout: parameter
name: Q_ACRO_YAW_RATE
range: 10 500
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L390
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.h#L390
units: deg/s
visual_asset_id: null
---

# QACRO mode yaw rate

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [ACRO_Y_RATE](../ACRO/ACRO_Y_RATE.html).

Please refer to the [ACRO_Y_RATE](../ACRO/ACRO_Y_RATE.html) documentation for detailed tuning instructions.
