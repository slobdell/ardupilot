---
layout: parameter
name: SB_V_EXT
display_name: Sidebar vertical extension
description: Increase of vertical length of the sidebar itens by this amount of lines. Applied equally both above and below the default setting.
default_value: 0
range: 0 10
units: 
group: SB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L246
---

# SB_V_EXT: Sidebar vertical extension

## Description
Increases the vertical length of the sidebar elements (like the airspeed and altitude tapes) by this many character lines. The extension is applied equally both above and below the default center point.

## Values
- **Range:** 0 to 10
- **Default:** 0

## Description
This parameter controls the "height" of the data tapes displayed in the **OSD (On-Screen Display)**.

- **Function:** If you want a taller speed or altitude tape to see a wider range of values at a glance, increasing this parameter will grow the tapes vertically.
- **Unit:** Each increment adds two character lines total (one above the center and one below).
- **Layout:** Note that making the sidebars too tall may cause them to overlap with other OSD elements at the top or bottom of the screen.

