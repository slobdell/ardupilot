---
layout: parameter
name: FFT_OPTIONS
display_name: FFT options
description: Configuration bitmask for the FFT module.
default_value: 0
range: 
units: 
group: FFT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GyroFFT/AP_GyroFFT.cpp
---

# FFT options (FFT_OPTIONS)

## Description
Bitmask for advanced FFT behaviors.
*   **Bit 0: Enable post-filter FFT (Analyze noise *after* software filters)**
*   **Bit 1: Check motor noise (Use ESC RPM as a reference)**