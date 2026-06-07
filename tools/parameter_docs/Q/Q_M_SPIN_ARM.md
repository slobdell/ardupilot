---alias_target: MOT_SPIN_ARM
default_value: AP_MOTORS_SPIN_ARM_DEFAULT
description: Point at which the motors start to spin expressed as a number from 0
  to 1 in the entire output range.  Should be lower than MOT_SPIN_MIN.
display_name: Motor Spin armed
group: Q
investigation_status: alias
layout: parameter
name: Q_M_SPIN_ARM
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L123
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.h#L163
units: null
visual_asset_id: null
---
# Motor Spin armed

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [MOT_SPIN_ARM](../MOT/MOT_SPIN_ARM.html).

Please refer to the [MOT_SPIN_ARM](../MOT/MOT_SPIN_ARM.html) documentation for detailed tuning instructions.
