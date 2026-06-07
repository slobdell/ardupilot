---
layout: parameter
name: FFT_ENABLE
display_name: Enable Gyro FFT analyser
description: Enables the real-time Fast Fourier Transform (FFT) analysis of gyroscope data for noise identification.
default_value: 0
range: 0 1
units: 
group: FFT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GyroFFT/AP_GyroFFT.cpp
---

# Enable Gyro FFT analyser (FFT_ENABLE)

## Description
Master switch for the Gyro FFT module. When enabled, the autopilot performs continuous frequency analysis of gyro noise, allowing for dynamic filtering of motor vibrations via the harmonic notch filter.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Requires reboot to take effect.**
*   **Highly recommended for modern multicopters to improve flight performance.**
