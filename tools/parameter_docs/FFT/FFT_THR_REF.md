---
layout: parameter
name: FFT_THR_REF
display_name: FFT learned thrust reference
description: Learned throttle level corresponding to the FFT_FREQ_HOVER frequency.
default_value: 0.35
range: 0.01 0.9
units: 
group: FFT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GyroFFT/AP_GyroFFT.cpp
---

# FFT learned thrust reference (FFT_THR_REF)

## Description
The throttle value (0.0 to 1.0) at which the aircraft was hovering when FFT_FREQ_HOVER was identified. This is used to scale the filter frequency as throttle changes.
