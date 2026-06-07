---
layout: parameter
name: OSD_BTN_DELAY
display_name: OSD Menu Button Delay
description: Debounce time (in ms) for navigating OSD menus using RC sticks.
default_value: 300
range: 0 3000
units: ms
group: OSD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD.cpp#L177
---

# OSD Menu Button Delay (OSD_BTN_DELAY)

## Description
`OSD_BTN_DELAY` determines the "Key Repeat" speed when navigating ArduPilot's On-Screen Display menus using your transmitter sticks. 

If this value is too short, the menu might "skip" entries or move too fast to control. If it is too long, the menu will feel sluggish and unresponsive.

## Tuning & Behavior
*   **Default:** 300 ms.
*   **Recommendation:** Leave at **300ms**. If you find it difficult to select specific items in the OSD setup menu, increase to **500ms**.