---
layout: parameter
name: OSD_DSARM_SCR
display_name: OSD Disarm Screen
description: Selects which OSD screen is shown when the vehicle is disarmed.
default_value: 0
range: 0 4
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L100
---

# OSD Disarm Screen (OSD_DSARM_SCR)

## Description
`OSD_DSARM_SCR` switches the OSD view when you land and disarm. This is often used to show a "Flight Summary" screen with max speed, total distance, and battery used.