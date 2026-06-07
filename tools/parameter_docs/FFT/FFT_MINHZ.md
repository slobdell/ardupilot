---
layout: parameter
name: FFT_MINHZ
display_name: Minimum Frequency
description: Lower bound of FFT frequency detection in Hz.
default_value: 50
range: 20 400
units: Hz
group: FFT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GyroFFT/AP_GyroFFT.cpp
---

# Minimum Frequency (FFT_MINHZ)

## Description
Defines the lowest frequency the FFT engine will monitor. This should be set slightly below the expected idle RPM of your motors (converted to Hz).
