---alias_target: MOT_PWM_MIN
default_value: 1000
description: This sets the min PWM output value in microseconds that will ever be
  output to the motors
display_name: PWM output minimum
group: Q
investigation_status: alias
layout: parameter
name: Q_M_PWM_MIN
range: 0 2000
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L101
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.h#L70
units: PWM
visual_asset_id: null
---
# PWM output minimum

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [MOT_PWM_MIN](../MOT/MOT_PWM_MIN.html).

Please refer to the [MOT_PWM_MIN](../MOT/MOT_PWM_MIN.html) documentation for detailed tuning instructions.
