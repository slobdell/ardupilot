---
layout: parameter
name: DIR_DZ
display_name: Wind vane deadzone
description: Wind vane deadzone when using analog sensor.
default_value: 0
range: 0 360
units: deg
group: DIR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp
---

# Wind vane deadzone (DIR_DZ)

## Description
A small range of movement around the zero-point that is ignored by the software to prevent rapid, jittery direction changes when the wind is perfectly head-on.