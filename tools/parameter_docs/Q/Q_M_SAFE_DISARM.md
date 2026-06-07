---alias_target: MOT_SAFE_DISARM
default_value: 0
description: Disables motor PWM output when disarmed
display_name: Motor PWM output disabled when disarmed
group: Q
investigation_status: alias
layout: parameter
name: Q_M_SAFE_DISARM
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L154
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.h#L170
units: null
visual_asset_id: null
---
# Motor PWM output disabled when disarmed

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [MOT_SAFE_DISARM](../MOT/MOT_SAFE_DISARM.html).

Please refer to the [MOT_SAFE_DISARM](../MOT/MOT_SAFE_DISARM.html) documentation for detailed tuning instructions.
