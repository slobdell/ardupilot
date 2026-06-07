---alias_target: WPNAV_JERK
default_value: 1.0f
description: Defines the horizontal jerk in m/s/s used during missions
display_name: Waypoint Jerk
group: Q
investigation_status: alias
layout: parameter
name: Q_WP_JERK
range: 1 20
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.cpp#L85
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.h#L252
units: m/s/s/s
visual_asset_id: null
---
# Waypoint Jerk

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [WPNAV_JERK](../WPNAV/WPNAV_JERK.html).

Please refer to the [WPNAV_JERK](../WPNAV/WPNAV_JERK.html) documentation for detailed tuning instructions.
