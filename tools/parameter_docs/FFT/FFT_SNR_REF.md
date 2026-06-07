---
layout: parameter
name: FFT_SNR_REF
display_name: FFT SNR reference threshold
description: Signal-to-Noise Ratio (SNR) threshold in dB required to identify a valid noise peak.
default_value: 25.0
range: 0.0 100.0
units: dB
group: FFT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GyroFFT/AP_GyroFFT.cpp
---

# FFT SNR reference threshold (FFT_SNR_REF)

## Description
Determines how prominent a vibration frequency must be above the background noise floor to be considered a "peak" and targeted by a filter.
