---alias_target: WPNAV_RADIUS
default_value: AC_FENCE_CIRCLE_RADIUS_DEFAULT
description: Circle fence radius which when breached will cause an RTL
display_name: Circular Fence Radius
group: Q
investigation_status: alias
layout: parameter
name: Q_WP_RADIUS
range: 30 10000
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Fence/AC_Fence.cpp#L89
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Fence/AC_Fence.h#L147
units: m
visual_asset_id: null
---
# Circular Fence Radius

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [WPNAV_RADIUS](../WPNAV/WPNAV_RADIUS.html).

Please refer to the [WPNAV_RADIUS](../WPNAV/WPNAV_RADIUS.html) documentation for detailed tuning instructions.
