---
layout: parameter
name: INS_HNTC4_ATT
display_name: Harmonic Notch Filter 4 Attenuation
description: The depth of the notch filter in dB.
default_value: 40
range: 10 100
units: dB
group: INS
visual_asset_id: notch_filter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L70
---

# Harmonic Notch Filter 4 Attenuation (INS_HNTC4_ATT)

## Description
`INS_HNTC4_ATT` determines how aggressively the fourth filter removes noise.

## Tuning & Behavior
*   **Default Value:** 40 dB.
*   **Recommendation:** Leave at **40**.