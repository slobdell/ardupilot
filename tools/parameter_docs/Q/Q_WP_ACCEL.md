---alias_target: WPNAV_ACCEL
default_value: WPNAV_ACCELERATION
description: Defines the horizontal acceleration in cm/s/s used during missions
display_name: Waypoint Acceleration
group: Q
investigation_status: alias
layout: parameter
name: Q_WP_ACCEL
range: 50 500
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.cpp#L61
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.h#L88
units: cm/s/s
visual_asset_id: null
---
# Waypoint Acceleration

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [WPNAV_ACCEL](../WPNAV/WPNAV_ACCEL.html).

Please refer to the [WPNAV_ACCEL](../WPNAV/WPNAV_ACCEL.html) documentation for detailed tuning instructions.
