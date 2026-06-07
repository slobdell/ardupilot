---
layout: parameter
name: INS_HNTC4_HMNCS
display_name: Harmonic Notch Filter 4 Harmonics
description: Bitmask of harmonics to filter.
default_value: 1
range: 0 31
units: 
group: INS
visual_asset_id: notch_filter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_config.cpp#L100
---

# Harmonic Notch Filter 4 Harmonics (INS_HNTC4_HMNCS)

## Description
`INS_HNTC4_HMNCS` tells the filter to target multiples of the base frequency.

*   **Bit 0 (1):** Fundamental frequency (1x).
*   **Bit 1 (2):** 2nd Harmonic (2x).
*   **Bit 2 (4):** 3rd Harmonic (3x).

## Tuning & Behavior
*   **Default Value:** 1 (Base freq only).
*   **Recommendation:** Set to **3** (1st + 2nd) or **7** (1st + 2nd + 3rd) if your FFT shows multiple spikes.