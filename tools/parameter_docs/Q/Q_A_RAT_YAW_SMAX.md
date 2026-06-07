---
layout: parameter
name: Q_A_RAT_YAW_SMAX
display_name: QuadPlane Yaw Axis Rate Slew Rate Limit
description: Limits the maximum rate of change of the motor output requested by the yaw rate controller for VTOL motors.
default_value: 0.0
range: 0 200
units: 
group: Q
visual_asset_id: atc_rat_pit_smax_diagram
investigation_status: alias
alias_target: ATC_RAT_YAW_SMAX
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_HELI_PID.cpp#L70
---

# QuadPlane Yaw Axis Rate Slew Rate Limit (Q_A_RAT_YAW_SMAX)

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [ATC_RAT_YAW_SMAX](../ATC/ATC_RAT_YAW_SMAX.html).

Please refer to the [ATC_RAT_YAW_SMAX](../ATC/ATC_RAT_YAW_SMAX.html) documentation for detailed tuning instructions.