---alias_target: MOT_YAW_SV_ANGLE
default_value: 45
description: This is the pitch angle at which tailsitter aircraft will change from
  VTOL control to fixed wing control.
display_name: Tailsitter fixed wing transition angle
group: Q
investigation_status: alias
layout: parameter
name: Q_M_YAW_SV_ANGLE
range: 5 80
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/tailsitter.cpp#L40
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/tailsitter.h#L92
units: deg
visual_asset_id: null
---
# Tailsitter fixed wing transition angle

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [MOT_YAW_SV_ANGLE](../MOT/MOT_YAW_SV_ANGLE.html).

Please refer to the [MOT_YAW_SV_ANGLE](../MOT/MOT_YAW_SV_ANGLE.html) documentation for detailed tuning instructions.
