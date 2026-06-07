---alias_target: PSC_ANGLE_MAX
default_value: 3000
description: Maximum lean angle in all VTOL flight modes
display_name: Angle Max
group: Q
investigation_status: alias
layout: parameter
name: Q_P_ANGLE_MAX
range: 1000 8000
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L30
units: cdeg
visual_asset_id: null
---
# Angle Max

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [PSC_ANGLE_MAX](../PSC/PSC_ANGLE_MAX.html).

Please refer to the [PSC_ANGLE_MAX](../PSC/PSC_ANGLE_MAX.html) documentation for detailed tuning instructions.
