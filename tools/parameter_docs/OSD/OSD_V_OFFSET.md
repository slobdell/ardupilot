---
layout: parameter
name: OSD_V_OFFSET
display_name: OSD Vertical Offset
description: Shifts the entire OSD image up or down on the screen to compensate for camera alignment or monitor differences.
default_value: 16
range: 0 31
units: 
group: OSD
visual_asset_id: osd_switch_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L100
---

# OSD Vertical Offset (OSD_V_OFFSET)

## Description
`OSD_V_OFFSET` centers the OSD on your screen.

Due to differences in analog video formats (PAL vs NTSC) and camera processing, the OSD might appear too high or too low, cutting off text at the edges. This parameter shifts the entire layout vertically.

## Tuning & Behavior
*   **Adjustment:** Increase the value to shift the OSD **Down**. Decrease to shift it **Up**.