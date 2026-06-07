---
layout: parameter
name: DIR_OFS
display_name: Wind vane headwind offset
description: Angle offset when analog windvane is indicating a headwind, ie 0 degrees relative to vehicle.
default_value: 0.0
range: 0 360
units: deg
group: DIR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp
---

# Wind vane headwind offset (DIR_OFS)

## Description
Software calibration used to align the zero-point of the wind vane with the longitudinal axis (nose) of the aircraft.