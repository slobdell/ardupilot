---alias_target: ATC_THR_MIX_MAN
default_value: AC_ATTITUDE_CONTROL_MAN_DEFAULT
description: Throttle vs attitude control prioritisation used during manual flight
  (higher values mean we prioritise attitude control over throttle)
display_name: Throttle Mix Manual
group: Q
investigation_status: alias
layout: parameter
name: Q_A_THR_MIX_MAN
range: 0.1 0.9
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L311
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.h#L70
units: null
visual_asset_id: null
---
# Throttle Mix Manual

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [ATC_THR_MIX_MAN](../ATC/ATC_THR_MIX_MAN.html).

Please refer to the [ATC_THR_MIX_MAN](../ATC/ATC_THR_MIX_MAN.html) documentation for detailed tuning instructions.
