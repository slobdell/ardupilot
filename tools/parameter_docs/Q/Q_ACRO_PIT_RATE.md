---
alias_target: ACRO_RP_RATE
default_value: 180
description: The maximum pitch rate at full stick deflection in QACRO mode
display_name: QACRO mode pitch rate
group: Q
investigation_status: alias
layout: parameter
name: Q_ACRO_PIT_RATE
range: 10 500
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L381
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.h#L389
units: deg/s
visual_asset_id: null
---

# QACRO mode pitch rate

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [ACRO_RP_RATE](../ACRO/ACRO_RP_RATE.html).

Please refer to the [ACRO_RP_RATE](../ACRO/ACRO_RP_RATE.html) documentation for detailed tuning instructions.
