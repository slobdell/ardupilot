---alias_target: ATC_RATE_FF_ENAB
default_value: AC_ATTITUDE_CONTROL_RATE_BF_FF_DEFAULT
description: Controls whether body-frame rate feedforward is enabled or disabled
display_name: Rate Feedforward Enable
group: Q
investigation_status: alias
layout: parameter
name: Q_A_RATE_FF_ENAB
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L53
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.h#L328
units: null
visual_asset_id: null
---
# Rate Feedforward Enable

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [ATC_RATE_FF_ENAB](../ATC/ATC_RATE_FF_ENAB.html).

Please refer to the [ATC_RATE_FF_ENAB](../ATC/ATC_RATE_FF_ENAB.html) documentation for detailed tuning instructions.
