---
layout: parameter
name: DIR_FILT
display_name: apparent Wind vane direction filter
description: apparent Wind vane direction low pass filter frequency.
default_value: 0.5
range: 0 10
units: Hz
group: DIR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp
---

# apparent Wind vane direction filter (DIR_FILT)

## Description
Low-pass filter frequency for smoothing the apparent wind direction data. Helps to remove noise caused by turbulence or physical sensor vibration.