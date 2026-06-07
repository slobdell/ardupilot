---alias_target: WPNAV_SPEED
default_value: LOITER_SPEED_DEFAULT
description: Defines the maximum speed in cm/s which the aircraft will travel horizontally
  while in loiter mode
display_name: Loiter Horizontal Maximum Speed
group: Q
investigation_status: alias
layout: parameter
name: Q_WP_SPEED
range: 20 3500
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_Loiter.cpp#L37
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_Loiter.h#L79
units: cm/s
visual_asset_id: null
---
# Loiter Horizontal Maximum Speed

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [WPNAV_SPEED](../WPNAV/WPNAV_SPEED.html).

Please refer to the [WPNAV_SPEED](../WPNAV/WPNAV_SPEED.html) documentation for detailed tuning instructions.
