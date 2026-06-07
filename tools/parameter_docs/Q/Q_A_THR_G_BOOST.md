---alias_target: ATC_THR_G_BOOST
default_value: 0.0f
description: Throttle-gain boost ratio. A value of 0 means no boosting is applied,
  a value of 1 means full boosting is applied. Describes the ratio increase that is
  applied to angle P and PD on pitch and roll.
display_name: Throttle-gain boost
group: Q
investigation_status: alias
layout: parameter
name: Q_A_THR_G_BOOST
range: 0 1
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L318
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.h#L153
units: null
visual_asset_id: null
---
# Throttle-gain boost

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [ATC_THR_G_BOOST](../ATC/ATC_THR_G_BOOST.html).

Please refer to the [ATC_THR_G_BOOST](../ATC/ATC_THR_G_BOOST.html) documentation for detailed tuning instructions.
