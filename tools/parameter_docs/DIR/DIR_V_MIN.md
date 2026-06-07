---
layout: parameter
name: DIR_V_MIN
display_name: Wind vane voltage minimum
description: Minimum voltage supplied by analog wind vane.
default_value: 0.0
range: 0 5.0
units: V
group: DIR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp
---

# Wind vane voltage minimum (DIR_V_MIN)

## Description
Calibration point for the minimum voltage output of the analog wind vane sensor, corresponding to its lowest range.