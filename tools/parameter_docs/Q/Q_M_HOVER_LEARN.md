---alias_target: MOT_HOVER_LEARN
default_value: COMPASS_LEARN_DEFAULT
description: Enable or disable the automatic learning of compass offsets. You can
  enable learning either using a compass-only method that is suitable only for fixed
  wing aircraft or using the offsets learnt by the active EKF state estimator. If
  this option is enabled then the learnt offsets are saved when you disarm the vehicle.
  If InFlight learning is enabled then the compass with automatically start learning
  once a flight starts (must be armed). While InFlight learning is running you cannot
  use position control modes.
display_name: Learn compass offsets automatically
group: Q
investigation_status: alias
layout: parameter
name: Q_M_HOVER_LEARN
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Compass/AP_Compass.cpp#L122
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Compass/AP_Compass.h#L229
units: null
visual_asset_id: null
---
# Learn compass offsets automatically

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [MOT_HOVER_LEARN](../MOT/MOT_HOVER_LEARN.html).

Please refer to the [MOT_HOVER_LEARN](../MOT/MOT_HOVER_LEARN.html) documentation for detailed tuning instructions.
