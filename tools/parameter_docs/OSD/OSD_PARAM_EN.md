---
layout: parameter
name: OSD_PARAM_EN
display_name: OSD Parameter Entry Enable
description: Enables or disables a specific parameter entry on an OSD tuning screen.
default_value: 0
range: 0 1
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L40
---

# OSD Parameter Entry Enable (OSD_PARAM_EN)

## Description
`OSD_PARAM_EN` toggles the visibility of a specific parameter on the OSD's in-flight tuning menu.

ArduPilot supports special "Parameter Screens" where you can adjust PIDs or other settings while flying using your transmitter sticks. This parameter determines if a specific slot in that menu is active.

*   **0: Disabled.**
*   **1: Enabled.**
