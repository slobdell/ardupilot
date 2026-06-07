---
alias_target: RNGFND1_TYPE
default_value: TILT_TYPE_CONTINUOUS
description: This is the type of tiltrotor when TILT_MASK is non-zero. A continuous
  tiltrotor can tilt the rotors to any angle on demand. A binary tiltrotor assumes
  a retract style servo where the servo is either fully forward or fully up. In both
  cases the servo can't move faster than Q_TILT_RATE. A vectored yaw tiltrotor will
  use the tilt of the motors to control yaw in hover, Bicopter tiltrotor must use
  the tailsitter frame class (10)
display_name: Tiltrotor type
group: RNGFNDA
investigation_status: alias
layout: parameter
name: RNGFNDA_TYPE
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/tiltrotor.cpp#L44
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/tiltrotor.h#L71
units: null
visual_asset_id: null
---

# Tiltrotor type

**Note:** This parameter is functionally identical to [RNGFND1_TYPE](../RNGFNDA/RNGFND1_TYPE.html).

Please refer to the documentation for the primary instance for detailed configuration instructions.
