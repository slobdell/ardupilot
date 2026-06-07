---alias_target: MOT_YAW_HEADROOM
default_value: AP_MOTORS_YAW_HEADROOM_DEFAULT
description: Yaw control is given at least this pwm in microseconds range
display_name: Matrix Yaw Min
group: Q
investigation_status: alias
layout: parameter
name: Q_M_YAW_HEADROOM
range: 0 500
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L43
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.h#L41
units: PWM
visual_asset_id: null
---
# Matrix Yaw Min

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [MOT_YAW_HEADROOM](../MOT/MOT_YAW_HEADROOM.html).

Please refer to the [MOT_YAW_HEADROOM](../MOT/MOT_YAW_HEADROOM.html) documentation for detailed tuning instructions.
