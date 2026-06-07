---
layout: parameter
name: EK3_HRT_FILT
display_name: EKF3 Height Rate Filter Frequency
description: The crossover frequency (in Hz) of the complementary filter used for height rate prediction.
default_value: 2.0
range: 0.1 30.0
units: Hz
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L593
---

# EKF3 Height Rate Filter Frequency (EK3_HRT_FILT)

## Description
`EK3_HRT_FILT` tunes the vertical velocity estimator.

It combines the accelerometer data (fast, noisy) with the barometer/GPS data (slow, smooth). This frequency determines the "crossover point."

## Tuning & Behavior
*   **Default Value:** 2.0 Hz.
*   **Higher Value:** More responsive to rapid climbs, but noisier.
*   **Lower Value:** Smoother velocity estimate, but slight lag.