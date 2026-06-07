---alias_target: MOT_SLEW_UP_TIME
default_value: AP_MOTORS_SLEW_TIME_DEFAULT
description: Time in seconds to slew output from zero to full. This is used to limit
  the rate at which output can change. Range is constrained between 0 and 0.5.
display_name: Output slew time for increasing throttle
group: Q
investigation_status: alias
layout: parameter
name: Q_M_SLEW_UP_TIME
range: 0 .5
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L198
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.h#L160
units: s
visual_asset_id: null
---
# Output slew time for increasing throttle

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [MOT_SLEW_UP_TIME](../MOT/MOT_SLEW_UP_TIME.html).

Please refer to the [MOT_SLEW_UP_TIME](../MOT/MOT_SLEW_UP_TIME.html) documentation for detailed tuning instructions.
