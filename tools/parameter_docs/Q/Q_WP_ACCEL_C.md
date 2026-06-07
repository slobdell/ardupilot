---alias_target: WPNAV_ACCEL_C
default_value: 0.0
description: Defines the maximum cornering acceleration in cm/s/s used during missions.  If
  zero uses 2x accel value.
display_name: Waypoint Cornering Acceleration
group: Q
investigation_status: alias
layout: parameter
name: Q_WP_ACCEL_C
range: 0 500
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.cpp#L102
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.h#L91
units: cm/s/s
visual_asset_id: null
---
# Waypoint Cornering Acceleration

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [WPNAV_ACCEL_C](../WPNAV/WPNAV_ACCEL_C.html).

Please refer to the [WPNAV_ACCEL_C](../WPNAV/WPNAV_ACCEL_C.html) documentation for detailed tuning instructions.
