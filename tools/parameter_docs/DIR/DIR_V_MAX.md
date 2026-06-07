---
layout: parameter
name: DIR_V_MAX
display_name: Wind vane voltage maximum
description: Maximum voltage supplied by analog wind vane.
default_value: 3.3
range: 0 5.0
units: V
group: DIR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp
---

# Wind vane voltage maximum (DIR_V_MAX)

## Description
Calibration point for the maximum voltage output of the analog wind vane sensor, corresponding to its highest range.