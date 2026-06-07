---alias_target: WPNAV_SPEED_DN
default_value: WPNAV_WP_SPEED_DOWN
description: Defines the speed in cm/s which the aircraft will attempt to maintain
  while descending during a WP mission
display_name: Waypoint Descent Speed Target
group: Q
investigation_status: alias
layout: parameter
name: Q_WP_SPEED_DN
range: 10 500
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.cpp#L52
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.h#L82
units: cm/s
visual_asset_id: null
---
# Waypoint Descent Speed Target

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [WPNAV_SPEED_DN](../WPNAV/WPNAV_SPEED_DN.html).

Please refer to the [WPNAV_SPEED_DN](../WPNAV/WPNAV_SPEED_DN.html) documentation for detailed tuning instructions.
