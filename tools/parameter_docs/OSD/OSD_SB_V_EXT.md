---
layout: parameter
name: OSD_SB_V_EXT
display_name: OSD Sidebar Vertical Extension
description: Increases the height (number of rows) of the altitude and airspeed sidebars.
default_value: 0
range: 0 5
units: 
group: OSD
visual_asset_id: osd_sidebar_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L100
---

# OSD Sidebar Vertical Extension (OSD_SB_V_EXT)

## Description
`OSD_SB_V_EXT` makes the OSD sidebars (the tapes on the left and right) taller.

A higher value increases the number of tick marks visible above and below the center, helping you see upcoming altitude or speed changes.