---alias_target: ATC_SLEW_YAW
default_value: AC_ATTITUDE_CONTROL_SLEW_YAW_DEFAULT_CDS
description: Maximum rate the yaw target can be updated in RTL and Auto flight modes
display_name: Yaw target slew rate
group: Q
investigation_status: alias
layout: parameter
name: Q_A_SLEW_YAW
range: 500 18000
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L34
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.h#L487
units: cdeg/s
visual_asset_id: null
---
# Yaw target slew rate

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [ATC_SLEW_YAW](../ATC/ATC_SLEW_YAW.html).

Please refer to the [ATC_SLEW_YAW](../ATC/ATC_SLEW_YAW.html) documentation for detailed tuning instructions.
