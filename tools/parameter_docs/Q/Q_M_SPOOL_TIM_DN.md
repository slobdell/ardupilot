---alias_target: MOT_SPOOL_TIM_DN
default_value: 0.0
description: This is the ratio of static pressure error to dynamic pressure generated
  by a negative wind relative velocity along the Z body axis. If the baro height estimate
  rises above truth height during descending flight (or forward flight with a high
  backwards lean angle, eg braking manoeuvre), then this should be a negative number.
  Multirotors can use this feature only if using EKF3 and if the EK3_DRAG_BCOEF_X
  and EK3_DRAG_BCOEF_Y parameters have been tuned.
display_name: Pressure error coefficient in negative Z direction (down)
group: Q
investigation_status: alias
layout: parameter
name: Q_M_SPOOL_TIM_DN
range: -1.0 1.0
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Baro/AP_Baro_Wind.cpp#L62
units: null
visual_asset_id: null
---
# Pressure error coefficient in negative Z direction (down)

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [MOT_SPOOL_TIM_DN](../MOT/MOT_SPOOL_TIM_DN.html).

Please refer to the [MOT_SPOOL_TIM_DN](../MOT/MOT_SPOOL_TIM_DN.html) documentation for detailed tuning instructions.
