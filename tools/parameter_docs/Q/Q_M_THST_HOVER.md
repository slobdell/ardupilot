---alias_target: MOT_THST_HOVER
default_value: AP_MOTORS_THST_HOVER_DEFAULT
description: Motor thrust needed to hover expressed as a number from 0 to 1
display_name: Thrust Hover Value
group: Q
investigation_status: alias
layout: parameter
name: Q_M_THST_HOVER
range: 0.125 0.6875
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L138
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.h#L48
units: null
visual_asset_id: null
---
# Thrust Hover Value

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [MOT_THST_HOVER](../MOT/MOT_THST_HOVER.html).

Please refer to the [MOT_THST_HOVER](../MOT/MOT_THST_HOVER.html) documentation for detailed tuning instructions.
