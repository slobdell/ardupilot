---
layout: parameter
name: FILT1_NOTCH_FREQ
display_name: Notch Filter Center Frequency
description: The specific frequency (in Hz) that the filter targets for removal.
default_value: 0
range: 10 500
units: Hz
group: FILT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/Filter/AP_NotchFilter_params.cpp#L17
---

# Notch Filter Center Frequency (FILT1_NOTCH_FREQ)

## Description
`FILT1_NOTCH_FREQ` defines the "Target" of a specialized electrical filter used to clean up noisy sensor data.

A **Notch Filter** removes one specific frequency while leaving others untouched. This is most commonly used to eliminate the vibration frequency of a drone's motors from the accelerometer or gyroscope data, allowing for much sharper and more stable flight control.

## Tuning & Behavior
*   **Default:** 0 (Disabled).
*   **Usage:** Find your frame's peak vibration frequency using the FFT diagnostic tool or by analyzing logs. Enter that frequency here.
*   **Effect:** Reduces mechanical "noise" that would otherwise confuse the PID controller.
*   **Integration:** Must be used with [FILT1_NOTCH_Q](FILT1_NOTCH_Q.html) to define the width of the filter.