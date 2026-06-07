---alias_target: PSC_JERK_D
default_value: 0
description: D Gain which produces an output that is proportional to the rate of change
  of the error
display_name: PID Derivative Gain
group: Q
investigation_status: alias
layout: parameter
name: Q_P_JERK_D
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_HELI_PID.cpp#L21
units: null
visual_asset_id: null
---
# PID Derivative Gain

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [PSC_JERK_D](../PSC/PSC_JERK_D.html).

Please refer to the [PSC_JERK_D](../PSC/PSC_JERK_D.html) documentation for detailed tuning instructions.
