---alias_target: LOIT_BRK_ACCEL
default_value: LOITER_BRAKE_ACCEL_DEFAULT
description: Loiter braking acceleration in cm/s/s. Higher values stop the copter
  more quickly when the stick is centered.
display_name: Loiter braking acceleration
group: Q
investigation_status: alias
layout: parameter
name: Q_LOIT_BRK_ACCEL
range: 25 250
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_Loiter.cpp#L55
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_Loiter.h#L81
units: cm/s/s
visual_asset_id: null
---
# Loiter braking acceleration

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [LOIT_BRK_ACCEL](../LOIT/LOIT_BRK_ACCEL.html).

Please refer to the [LOIT_BRK_ACCEL](../LOIT/LOIT_BRK_ACCEL.html) documentation for detailed tuning instructions.
