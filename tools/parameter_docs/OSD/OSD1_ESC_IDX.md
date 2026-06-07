---
layout: parameter
name: OSD1_ESC_IDX
display_name: OSD ESC Instance Selection (Instance 1)
description: Selects which ESC's telemetry data to display on this screen.
default_value: 0
range: 0 32
units: 
group: OSD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_Screen.cpp#L1174
---

# OSD ESC Instance Selection (OSD1_ESC_IDX)

## Description
`OSD1_ESC_IDX` determines which motor's data is shown if you have the [ESCTEMP](ESCTEMP.html) or [ESCRPM](ESCRPM.html) widgets active.

*   **0: Auto.** Shows the ESC with the highest value (e.g. the hottest motor or the fastest spin).
*   **1-32:** Fixes the display to a specific motor index.