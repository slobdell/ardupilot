---
layout: parameter
name: FFT_SAMPLE_MODE
display_name: FFT Sample Mode
description: Sampling mode (and therefore rate). 0: Gyro rate sampling, 1: Fast loop rate sampling.
default_value: 0
range: 0 4
units: 
group: FFT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GyroFFT/AP_GyroFFT.cpp
---

# FFT Sample Mode (FFT_SAMPLE_MODE)

## Description
Defines the source and rate of gyro data input to the FFT engine.
*   **0: Gyro rate (Standard)**
*   **1: Fast loop rate**
*   **Requires reboot to take effect.**