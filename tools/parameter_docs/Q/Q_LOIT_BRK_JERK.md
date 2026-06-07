---alias_target: LOIT_BRK_JERK
default_value: LOITER_BRAKE_JERK_DEFAULT
description: Loiter braking jerk in cm/s/s/s. Higher values will remove braking faster
  if the pilot moves the sticks during a braking maneuver.
display_name: Loiter braking jerk
group: Q
investigation_status: alias
layout: parameter
name: Q_LOIT_BRK_JERK
range: 500 5000
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_Loiter.cpp#L64
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_Loiter.h#L82
units: cm/s/s/s
visual_asset_id: null
---
# Loiter braking jerk

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [LOIT_BRK_JERK](../LOIT/LOIT_BRK_JERK.html).

Please refer to the [LOIT_BRK_JERK](../LOIT/LOIT_BRK_JERK.html) documentation for detailed tuning instructions.
