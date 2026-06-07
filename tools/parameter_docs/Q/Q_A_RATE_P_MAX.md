---alias_target: ATC_RATE_P_MAX
default_value: 45
description: This is the maximum angle of the tiltable motors at which multicopter
  control will be enabled. Beyond this angle the plane will fly solely as a fixed
  wing aircraft and the motors will tilt to their maximum angle at the TILT_RATE
display_name: Tiltrotor maximum VTOL angle
group: Q
investigation_status: alias
layout: parameter
name: Q_A_RATE_P_MAX
range: 20 80
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/tiltrotor.cpp#L38
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/tiltrotor.h#L80
units: deg
visual_asset_id: null
---
# Tiltrotor maximum VTOL angle

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [ATC_RATE_P_MAX](../ATC/ATC_RATE_P_MAX.html).

Please refer to the [ATC_RATE_P_MAX](../ATC/ATC_RATE_P_MAX.html) documentation for detailed tuning instructions.
