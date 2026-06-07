---alias_target: MOT_BAT_CURR_TC
default_value: AP_MOTORS_BAT_CURR_TC_DEFAULT
description: Time constant used to limit the maximum current
display_name: Motor Current Max Time Constant
group: Q
investigation_status: alias
layout: parameter
name: Q_M_BAT_CURR_TC
range: 0 10
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L131
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.h#L165
units: s
visual_asset_id: null
---
# Motor Current Max Time Constant

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [MOT_BAT_CURR_TC](../MOT/MOT_BAT_CURR_TC.html).

Please refer to the [MOT_BAT_CURR_TC](../MOT/MOT_BAT_CURR_TC.html) documentation for detailed tuning instructions.
