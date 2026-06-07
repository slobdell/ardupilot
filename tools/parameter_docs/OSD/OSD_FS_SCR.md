---
layout: parameter
name: OSD_FS_SCR
display_name: OSD Failsafe Screen
description: Selects which OSD screen is shown when a failsafe is active.
default_value: 0
range: 0 4
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L100
---

# OSD Failsafe Screen (OSD_FS_SCR)

## Description
`OSD_FS_SCR` switches the OSD view when an emergency (Failsafe) occurs. This allows you to have a dedicated "Emergency" screen that only shows critical info like GPS home direction and battery voltage in a high-visibility layout.