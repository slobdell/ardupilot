---
layout: parameter
name: OSD_OPTIONS
display_name: OSD Options
description: Bitmask of OSD display options (e.g., units, scrolling).
default_value: 0
range: 0 1024
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L100
---

# OSD Options (OSD_OPTIONS)

## Description
`OSD_OPTIONS` toggles advanced display features.

## Tuning & Behavior
*   **Bit 0:** Decimal pack voltage (Show 12.6V instead of 12V).
*   **Bit 1:** Invert pitch ladder.
*   **Bit 2:** Use alternative crosshair.