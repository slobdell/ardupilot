---alias_target: ATC_LAND_P_MULT
default_value: 1.0
description: Pitch gain multiplier active when landed. A factor of 1.0 means no reduction
  in gain while landed. Reduce this factor to reduce ground oscitation in the pitch
  axis.
display_name: Landed pitch gain multiplier
group: Q
investigation_status: alias
layout: parameter
name: Q_A_LAND_P_MULT
range: 0.25 1.0
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L167
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.h#L522
units: null
visual_asset_id: null
---
# Landed pitch gain multiplier

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [ATC_LAND_P_MULT](../ATC/ATC_LAND_P_MULT.html).

Please refer to the [ATC_LAND_P_MULT](../ATC/ATC_LAND_P_MULT.html) documentation for detailed tuning instructions.
