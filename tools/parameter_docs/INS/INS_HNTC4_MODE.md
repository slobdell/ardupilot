---
layout: parameter
name: INS_HNTC4_MODE
display_name: Harmonic Notch Filter 4 Dynamic Mode
description: Selects the tracking source for the fourth notch filter.
default_value: 0
range: 0 4
units: 
group: INS
visual_asset_id: notch_filter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L104
---

# Harmonic Notch Filter 4 Dynamic Mode (INS_HNTC4_MODE)

## Description
`INS_HNTC4_MODE` tells the fourth filter how to move.

*   **0:** Fixed frequency.
*   **1:** Throttle-based tracking.
*   **2:** RPM Sensor.
*   **3:** ESC Telemetry.
*   **4:** Dynamic FFT.

## Tuning & Behavior
*   **Default Value:** 0.