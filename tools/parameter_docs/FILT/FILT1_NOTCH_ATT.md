---
layout: parameter
name: FILT1_NOTCH_ATT
display_name: Notch Filter Attenuation
description: The "Depth" of the filter, defining how much the target frequency is reduced.
default_value: 0.1
range: 0 1.0
units: 
group: FILT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/Filter/AP_NotchFilter_params.cpp#L31
---

# Notch Filter Attenuation (FILT1_NOTCH_ATT)

## Description
`FILT1_NOTCH_ATT` defines how much of the noise is removed. A value of 0.1 reduces the signal at that frequency to 10% of its original strength.