---alias_target: MOT_BAT_VOLT_MIN
default_value: AP_MOTORS_BAT_VOLT_MIN_DEFAULT
description: Battery voltage compensation minimum voltage (voltage below this will
  have no additional scaling effect on thrust).  Recommend 3.3 * cell count, 0 = Disabled
display_name: Battery voltage compensation minimum voltage
group: Q
investigation_status: alias
layout: parameter
name: Q_M_BAT_VOLT_MIN
range: 6 42
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L75
units: V
visual_asset_id: null
---
# Battery voltage compensation minimum voltage

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [MOT_BAT_VOLT_MIN](../MOT/MOT_BAT_VOLT_MIN.html).

Please refer to the [MOT_BAT_VOLT_MIN](../MOT/MOT_BAT_VOLT_MIN.html) documentation for detailed tuning instructions.
