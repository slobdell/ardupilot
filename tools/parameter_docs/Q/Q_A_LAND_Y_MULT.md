---alias_target: ATC_LAND_Y_MULT
default_value: 1.0
description: Yaw gain multiplier active when landed. A factor of 1.0 means no reduction
  in gain while landed. Reduce this factor to reduce ground oscitation in the yaw
  axis.
display_name: Landed yaw gain multiplier
group: Q
investigation_status: alias
layout: parameter
name: Q_A_LAND_Y_MULT
range: 0.25 1.0
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L174
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.h#L523
units: null
visual_asset_id: null
---
# Landed yaw gain multiplier

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [ATC_LAND_Y_MULT](../ATC/ATC_LAND_Y_MULT.html).

Please refer to the [ATC_LAND_Y_MULT](../ATC/ATC_LAND_Y_MULT.html) documentation for detailed tuning instructions.
