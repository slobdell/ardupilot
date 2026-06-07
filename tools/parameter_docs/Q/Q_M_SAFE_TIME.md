---alias_target: MOT_SAFE_TIME
default_value: AP_MOTORS_SAFE_TIME_DEFAULT
description: Time taken to disable and enable the motor PWM output when disarmed and
  armed.
display_name: Time taken to disable and enable the motor PWM output when disarmed
  and armed.
group: Q
investigation_status: alias
layout: parameter
name: Q_M_SAFE_TIME
range: 0 5
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L216
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.h#L162
units: s
visual_asset_id: null
---
# Time taken to disable and enable the motor PWM output when disarmed and armed.

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [MOT_SAFE_TIME](../MOT/MOT_SAFE_TIME.html).

Please refer to the [MOT_SAFE_TIME](../MOT/MOT_SAFE_TIME.html) documentation for detailed tuning instructions.
