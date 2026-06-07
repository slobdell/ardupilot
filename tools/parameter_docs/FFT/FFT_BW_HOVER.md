---
layout: parameter
name: FFT_BW_HOVER
display_name: FFT learned bandwidth at hover
description: The automatically learned width (bandwidth) of the primary noise peak at hover.
default_value: 20
range: 0 200
units: Hz
group: FFT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GyroFFT/AP_GyroFFT.cpp
---

# FFT learned bandwidth at hover (FFT_BW_HOVER)

## Description
Records the typical width of the motor vibration peak during stable hover, used to configure the "Q" factor of the dynamic notch filter.