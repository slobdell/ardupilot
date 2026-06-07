---alias_target: WPNAV_TER_MARGIN
default_value: 2.0f
description: Vehicle will attempt to stay at least this distance (in meters) from
  objects while in GPS modes
display_name: Avoidance distance margin in GPS modes
group: Q
investigation_status: alias
layout: parameter
name: Q_WP_TER_MARGIN
range: 1 10
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AC_Avoid.cpp#L73
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AC_Avoid.h#L101
units: m
visual_asset_id: null
---
# Avoidance distance margin in GPS modes

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [WPNAV_TER_MARGIN](../WPNAV/WPNAV_TER_MARGIN.html).

Please refer to the [WPNAV_TER_MARGIN](../WPNAV/WPNAV_TER_MARGIN.html) documentation for detailed tuning instructions.
