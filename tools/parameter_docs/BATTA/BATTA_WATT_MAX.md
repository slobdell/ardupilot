---
alias_target: BATT_WATT_MAX
default_value: 45
description: This is the maximum angle of the tiltable motors at which multicopter
  control will be enabled. Beyond this angle the plane will fly solely as a fixed
  wing aircraft and the motors will tilt to their maximum angle at the TILT_RATE
display_name: Tiltrotor maximum VTOL angle
group: BATTA
investigation_status: alias
layout: parameter
name: BATTA_WATT_MAX
range: 20 80
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/tiltrotor.cpp#L38
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/tiltrotor.h#L80
units: deg
visual_asset_id: null
---

# Tiltrotor maximum VTOL angle

**Note:** This parameter configures Battery Monitor A. It functions identically to [BATT_WATT_MAX](../BATT/BATT_WATT_MAX.html).
