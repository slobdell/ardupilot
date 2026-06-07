---
layout: parameter
name: FFT_MAXHZ
display_name: Maximum Frequency
description: Upper bound of FFT frequency detection in Hz.
default_value: 450
range: 20 495
units: Hz
group: FFT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GyroFFT/AP_GyroFFT.cpp
---

# Maximum Frequency (FFT_MAXHZ)

## Description
Defines the highest frequency the FFT engine will monitor. Typically set based on the maximum expected motor RPM.
