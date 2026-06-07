---
layout: parameter
name: FFT_WINDOW_OLAP
display_name: FFT window overlap
description: Percentage of window to be overlapped before another frame is processed.
default_value: 0.5
range: 0 0.9
units: 
group: FFT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GyroFFT/AP_GyroFFT.cpp
---

# FFT window overlap (FFT_WINDOW_OLAP)

## Description
Controls how much data from the previous FFT window is reused in the next calculation. A higher overlap (e.g., 0.75) results in smoother tracking of noise peaks.
