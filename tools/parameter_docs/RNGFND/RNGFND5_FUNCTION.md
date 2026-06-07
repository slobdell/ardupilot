---
alias_target: RNGFND1_FUNCTION
default_value: 0
description: Control over what function is used to calculate distance. For a linear
  function, the distance is (voltage-offset)*scaling. For a inverted function the
  distance is (offset-voltage)*scaling. For a hyperbolic function the distance is
  scaling/(voltage-offset). The functions return the distance in meters.
display_name: Rangefinder function
group: RNGFND
investigation_status: alias
layout: parameter
name: RNGFND5_FUNCTION
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L50
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.h#L29
units: ''
visual_asset_id: null
---

# Rangefinder function

**Note:** This parameter functions identically to [RNGFND1_FUNCTION](../RNGFND/RNGFND1_FUNCTION.html).
