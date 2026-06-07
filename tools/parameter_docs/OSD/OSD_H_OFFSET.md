---
layout: parameter
name: OSD_H_OFFSET
display_name: OSD Horizontal Offset
description: Shifts the entire OSD image left or right on the screen.
default_value: 32
range: 0 63
units: 
group: OSD
visual_asset_id: osd_switch_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L100
---

# OSD Horizontal Offset (OSD_H_OFFSET)

## Description
`OSD_H_OFFSET` centers the OSD horizontally.

*   **Adjustment:** Increase the value to shift the OSD **Right**. Decrease to shift it **Left**.