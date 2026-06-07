---alias_target: MOT_SPOOL_TIME
default_value: AP_MOTORS_SPOOL_UP_TIME_DEFAULT
description: Time in seconds to spool up the motors from zero to min throttle.
display_name: Spool up time
group: Q
investigation_status: alias
layout: parameter
name: Q_M_SPOOL_TIME
range: 0.05 2
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L172
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.h#L176
units: s
visual_asset_id: null
---
# Spool up time

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [MOT_SPOOL_TIME](../MOT/MOT_SPOOL_TIME.html).

Please refer to the [MOT_SPOOL_TIME](../MOT/MOT_SPOOL_TIME.html) documentation for detailed tuning instructions.
