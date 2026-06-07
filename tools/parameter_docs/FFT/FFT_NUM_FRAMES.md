---
layout: parameter
name: FFT_NUM_FRAMES
display_name: FFT output averaging
description: Number of output frequency frames to retain and average.
default_value: 0
range: 0 8
units: 
group: FFT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GyroFFT/AP_GyroFFT.cpp
---

# FFT output averaging (FFT_NUM_FRAMES)

## Description
Smoothing factor for the FFT output. Averaging multiple frames reduces "jitter" in the tracked frequency but adds a small amount of latency to the filter's response.
*   **0: No averaging (Fastest)**