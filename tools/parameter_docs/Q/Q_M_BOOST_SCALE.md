---alias_target: MOT_BOOST_SCALE
default_value: 0
description: Scaling factor for first compass to compensate for sensor scaling errors.
  If this is 0 then no scaling is done
display_name: Compass1 scale factor
group: Q
investigation_status: alias
layout: parameter
name: Q_M_BOOST_SCALE
range: 0 1.3
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Compass/AP_Compass.cpp#L592
units: null
visual_asset_id: null
---
# Compass1 scale factor

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [MOT_BOOST_SCALE](../MOT/MOT_BOOST_SCALE.html).

Please refer to the [MOT_BOOST_SCALE](../MOT/MOT_BOOST_SCALE.html) documentation for detailed tuning instructions.
