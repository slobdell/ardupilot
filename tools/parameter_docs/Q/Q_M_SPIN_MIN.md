---alias_target: MOT_SPIN_MIN
default_value: AP_MOTORS_SPIN_MIN_DEFAULT
description: Point at which the thrust starts expressed as a number from 0 to 1 in
  the entire output range.  Should be higher than MOT_SPIN_ARM.
display_name: Motor Spin minimum
group: Q
investigation_status: alias
layout: parameter
name: Q_M_SPIN_MIN
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L116
units: null
visual_asset_id: null
---
# Motor Spin minimum

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [MOT_SPIN_MIN](../MOT/MOT_SPIN_MIN.html).

Please refer to the [MOT_SPIN_MIN](../MOT/MOT_SPIN_MIN.html) documentation for detailed tuning instructions.
