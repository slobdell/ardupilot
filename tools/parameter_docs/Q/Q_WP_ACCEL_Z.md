---alias_target: WPNAV_ACCEL_Z
default_value: WPNAV_WP_ACCEL_Z_DEFAULT
description: Defines the vertical acceleration in cm/s/s used during missions
display_name: Waypoint Vertical Acceleration
group: Q
investigation_status: alias
layout: parameter
name: Q_WP_ACCEL_Z
range: 50 500
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.cpp#L70
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.h#L85
units: cm/s/s
visual_asset_id: null
---
# Waypoint Vertical Acceleration

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [WPNAV_ACCEL_Z](../WPNAV/WPNAV_ACCEL_Z.html).

Please refer to the [WPNAV_ACCEL_Z](../WPNAV/WPNAV_ACCEL_Z.html) documentation for detailed tuning instructions.
