---
layout: parameter
name: WNDVN_SPEED_FILT
display_name: Wind Speed Low-Pass Filter
description: Cutoff frequency for the filter that smooths raw apparent wind speed data.
default_value: 0.5
range: 0 20
units: Hz
group: WNDVN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp#L152
---

# Wind Speed Low-Pass Filter (WNDVN_SPEED_FILT)

## Description
`WNDVN_SPEED_FILT` smooths out the "gusty" or noisy data from your anemometer (wind speed sensor).

Wind speed is naturally turbulent, especially near the surface. Without a filter, the reported wind speed would jump around rapidly, which can make the sail trimming or mission logic twitchy. This parameter sets the cutoff frequency for a low-pass filter to provide a stable "Apparent Wind" speed.

*   **Higher Frequency (e.g. 2.0 Hz):** More responsive to quick wind shifts, but more noise.
*   **Lower Frequency (e.g. 0.1 Hz):** Very smooth data, but slow to react to real gusts.

## Tuning & Behavior
*   **Default:** 0.5 Hz.
*   **Recommendation:** Leave at **0.5 Hz**. If your telemetry shows very jumpy wind speeds even in steady air, reduce this value to **0.2 Hz**.