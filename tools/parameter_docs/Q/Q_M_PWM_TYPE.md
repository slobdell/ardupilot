---alias_target: MOT_PWM_TYPE
default_value: TILT_TYPE_CONTINUOUS
description: This is the type of tiltrotor when TILT_MASK is non-zero. A continuous
  tiltrotor can tilt the rotors to any angle on demand. A binary tiltrotor assumes
  a retract style servo where the servo is either fully forward or fully up. In both
  cases the servo can't move faster than Q_TILT_RATE. A vectored yaw tiltrotor will
  use the tilt of the motors to control yaw in hover, Bicopter tiltrotor must use
  the tailsitter frame class (10)
display_name: Tiltrotor type
group: Q
investigation_status: alias
layout: parameter
name: Q_M_PWM_TYPE
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/tiltrotor.cpp#L44
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/tiltrotor.h#L71
units: null
visual_asset_id: null
---
# Tiltrotor type

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [MOT_PWM_TYPE](../MOT/MOT_PWM_TYPE.html).

Please refer to the [MOT_PWM_TYPE](../MOT/MOT_PWM_TYPE.html) documentation for detailed tuning instructions.
