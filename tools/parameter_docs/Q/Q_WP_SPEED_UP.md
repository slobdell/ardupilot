---alias_target: WPNAV_SPEED_UP
default_value: WPNAV_WP_SPEED_UP
description: Defines the speed in cm/s which the aircraft will attempt to maintain
  while climbing during a WP mission
display_name: Waypoint Climb Speed Target
group: Q
investigation_status: alias
layout: parameter
name: Q_WP_SPEED_UP
range: 10 1000
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.cpp#L43
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.h#L79
units: cm/s
visual_asset_id: null
---
# Waypoint Climb Speed Target

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [WPNAV_SPEED_UP](../WPNAV/WPNAV_SPEED_UP.html).

Please refer to the [WPNAV_SPEED_UP](../WPNAV/WPNAV_SPEED_UP.html) documentation for detailed tuning instructions.
