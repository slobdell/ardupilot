---alias_target: ATC_THR_MIX_MIN
default_value: AC_ATTITUDE_CONTROL_MIN_DEFAULT
description: Throttle vs attitude control prioritisation used when landing (higher
  values mean we prioritise attitude control over throttle)
display_name: Throttle Mix Minimum
group: Q
investigation_status: alias
layout: parameter
name: Q_A_THR_MIX_MIN
range: 0.1 0.25
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L297
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.h#L69
units: null
visual_asset_id: null
---
# Throttle Mix Minimum

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [ATC_THR_MIX_MIN](../ATC/ATC_THR_MIX_MIN.html).

Please refer to the [ATC_THR_MIX_MIN](../ATC/ATC_THR_MIX_MIN.html) documentation for detailed tuning instructions.
