---alias_target: ATC_INPUT_TC
default_value: AC_ATTITUDE_CONTROL_INPUT_TC_DEFAULT
description: Attitude control input time constant.  Low numbers lead to sharper response,
  higher numbers to softer response
display_name: Attitude control input time constant
group: Q
investigation_status: alias
layout: parameter
name: Q_A_INPUT_TC
range: 0 1
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L153
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.h#L150
units: s
visual_asset_id: null
---
# Attitude control input time constant

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [ATC_INPUT_TC](../ATC/ATC_INPUT_TC.html).

Please refer to the [ATC_INPUT_TC](../ATC/ATC_INPUT_TC.html) documentation for detailed tuning instructions.
