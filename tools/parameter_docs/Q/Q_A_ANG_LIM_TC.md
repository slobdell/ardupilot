---alias_target: ATC_ANG_LIM_TC
default_value: AC_ATTITUDE_CONTROL_ANGLE_LIMIT_TC_DEFAULT
description: Angle Limit (to maintain altitude) Time Constant
display_name: Angle Limit (to maintain altitude) Time Constant
group: Q
investigation_status: alias
layout: parameter
name: Q_A_ANG_LIM_TC
range: 0.5 10.0
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L113
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.h#L515
units: null
visual_asset_id: null
---
# Angle Limit (to maintain altitude) Time Constant

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [ATC_ANG_LIM_TC](../ATC/ATC_ANG_LIM_TC.html).

Please refer to the [ATC_ANG_LIM_TC](../ATC/ATC_ANG_LIM_TC.html) documentation for detailed tuning instructions.
