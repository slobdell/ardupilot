---
layout: parameter
name: SB_H_OFS
display_name: Sidebar horizontal offset
description: Extends the spacing between the sidebar elements by this amount of columns. Positive values increases the width to the right of the screen.
default_value: 0
range: 0 20
units: 
group: SB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L239
---

# SB_H_OFS: Sidebar horizontal offset

## Description
Extends the spacing between the sidebar elements (like the artificial horizon and the tapes) by this amount of columns. Positive values increase the width to the right of the screen.

## Values
- **Range:** 0 to 20
- **Default:** 0

## Description
This parameter is used to fine-tune the layout of the **OSD (On-Screen Display)** sidebars.

- **Function:** If you find that the speed and altitude tapes are too close to the center of the screen (obscuring the horizon or the crosshair), increasing this value will push them further towards the edges.
- **Unit:** Each increment corresponds to one character column width on the OSD screen.
- **Alignment:** This offset is typically applied to both left and right sidebars to maintain symmetry.

