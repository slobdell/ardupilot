---
layout: parameter
name: FFT_FREQ_HOVER
display_name: FFT learned hover frequency
description: The automatically learned peak noise frequency during stable hover.
default_value: 80.0
range: 0 250
units: Hz
group: FFT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GyroFFT/AP_GyroFFT.cpp
---

# FFT learned hover frequency (FFT_FREQ_HOVER)

## Description
This value is automatically populated by the flight controller as it identifies the primary motor noise frequency while hovering. It serves as a baseline for the harmonic notch filter.