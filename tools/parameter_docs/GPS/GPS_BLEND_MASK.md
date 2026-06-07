---
layout: parameter
name: GPS_BLEND_MASK
display_name: Multi GPS Blending Mask
description: Bitmask that determines which metrics are used to calculate the weighting when blending data from two GPS receivers.
default_value: 5
range: 0 7
units: 
group: GPS
visual_asset_id: gps_config_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_GPS/AP_GPS.cpp#L236
---

# Multi GPS Blending Mask (GPS_BLEND_MASK)

## Description
`GPS_BLEND_MASK` controls the "Recipe" for merging two GPS signals into one.

When `GPS_AUTO_SWITCH = 2 (Blend)`, ArduPilot doesn't just pick one GPS; it merges both into a single "Blended" solution. This parameter decides which metrics are used to determine how much to trust each GPS.

*   **Bit 0 (1): Horizontal Position Accuracy.** Use the reported horizontal error (hAcc) to weigh the blend.
*   **Bit 1 (2): Vertical Position Accuracy.** Use the reported vertical error (vAcc).
*   **Bit 2 (4): Speed Accuracy.** Use the velocity error (sAcc).

## Tuning & Behavior
*   **Default Value:** 5 (Horizontal + Speed).
*   **Recommendation:** Leave at **5**. Trusting reported vertical accuracy (Bit 1) can sometimes lead to altitude jumps if one GPS has a sudden change in its altitude noise model.