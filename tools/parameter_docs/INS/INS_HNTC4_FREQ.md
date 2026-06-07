---
layout: parameter
name: INS_HNTC4_FREQ
display_name: Harmonic Notch Filter 4 Frequency
description: The center frequency (in Hz) of the fourth harmonic notch filter.
default_value: 80
range: 10 500
units: Hz
group: INS
visual_asset_id: notch_filter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L120
---

# Harmonic Notch Filter 4 Frequency (INS_HNTC4_FREQ)

## Description
`INS_HNTC4_FREQ` sets the target frequency for the fourth notch filter.

ArduPilot allows you to stack multiple notch filters. You might use Filter 1 (`HNTCH`) for the motors, and Filter 2 (`HNTC2`) for a specific frame resonance. Filter 4 provides yet another layer of surgical noise removal.

*   **Static Mode:** This is the fixed frequency to remove.
*   **Dynamic Mode:** This is the reference frequency at the reference throttle/RPM.

## Tuning & Behavior
*   **Default Value:** 80 Hz.
*   **Recommendation:** Use this only if you have a complex noise profile with multiple independent peaks that Filters 1, 2, and 3 couldn't handle.