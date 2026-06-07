---
layout: parameter
name: FFT_HMNC_FIT
display_name: FFT harmonic fit threshold
description: Percentage threshold at which signals are determined to be harmonics of each other.
default_value: 10
range: 0 100
units: %
group: FFT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GyroFFT/AP_GyroFFT.cpp
---

# FFT harmonic fit threshold (FFT_HMNC_FIT)

## Description
Advanced setting used to group multiple detected frequencies as harmonics of a single fundamental motor frequency. This improves the reliability of the dynamic notch filter by ensuring it tracks the core vibration source.

## Tuning & Behavior
*   **Default Value:** 10 %
*   **A value of 0 disables harmonic matching.**