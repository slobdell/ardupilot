---
layout: parameter
name: INS_HNTC4_BW
display_name: Harmonic Notch Filter 4 Bandwidth
description: The bandwidth (in Hz) of the fourth harmonic notch filter.
default_value: 40
range: 10 250
units: Hz
group: INS
visual_asset_id: notch_filter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L120
---

# Harmonic Notch Filter 4 Bandwidth (INS_HNTC4_BW)

## Description
`INS_HNTC4_BW` sets the width of the notch for the fourth filter.

## Tuning & Behavior
*   **Default Value:** 40 Hz.
*   **Recommendation:** Set to **half of INS_HNTC4_FREQ**.