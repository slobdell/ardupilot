---
layout: parameter
name: DSARM_SCR
display_name: OSD Disarm Screen
description: OSD Screen to show when disarmed. 0 for current screen.
default_value: 0
range: 0 4
units: 
group: DSARM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD.cpp
---

# OSD Disarm Screen (DSARM_SCR)

## Description
Specifies which OSD layout should be automatically displayed when the vehicle is disarmed. 
*   **A value of 0 keeps the current OSD screen active.**