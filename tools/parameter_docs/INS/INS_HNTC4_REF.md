---
layout: parameter
name: INS_HNTC4_REF
display_name: Harmonic Notch Filter 4 Reference
description: The reference sensor value used to scale the notch frequency.
default_value: 0
range: 0 1.0
units: 
group: INS
visual_asset_id: notch_filter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L95
---

# Harmonic Notch Filter 4 Reference (INS_HNTC4_REF)

## Description
`INS_HNTC4_REF` scales the dynamic frequency for the fourth filter.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Usage:** Set to Hover Throttle if using Mode 1.