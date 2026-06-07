---
layout: parameter
name: FFT_HMNC_PEAK
display_name: FFT harmonic peak target
description: Defines which noise peak is targeted for filtering.
default_value: 0
range: 0 5
units: 
group: FFT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GyroFFT/AP_GyroFFT.cpp
---

# FFT harmonic peak target (FFT_HMNC_PEAK)

## Description
Specifies the strategy for selecting which vibration peak the FFT should track.
*   **0: Auto (Recommended)**
*   **1: Highest energy peak**
*   **4: Roll-Axis only**
*   **5: Pitch-Axis only**