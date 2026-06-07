---
layout: parameter
name: FFT_WINDOW_SIZE
display_name: FFT window size
description: Size of window to be used in FFT calculations. Must be a power of 2.
default_value: 32
range: 32 1024
units: 
group: FFT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GyroFFT/AP_GyroFFT.cpp
---

# FFT window size (FFT_WINDOW_SIZE)

## Description
Determines the balance between frequency resolution and time resolution.
*   **Larger windows (e.g., 128, 256) provide more precise frequency identification but have higher latency and CPU usage.**
*   **Smaller windows (e.g., 32, 64) react faster to changing noise but are less precise.**
