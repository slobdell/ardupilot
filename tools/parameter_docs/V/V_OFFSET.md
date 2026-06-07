---
layout: parameter
name: V_OFFSET
display_name: OSD vertical offset
description: Sets vertical offset of the osd inside image.
default_value: 16
range: 0 31
units: 
group: V
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L105
---

# V_OFFSET: OSD vertical offset

## Description
Sets vertical offset of the osd inside image.

## Values
- **Range:** 0 to 31
- **Default:** 16

## Description
This parameter centers the OSD overlay vertically on your video screen.

- **Function:** Because different cameras (PAL vs NTSC) and video transmitters have different timing, the OSD text might appear too high or too low. This value shifts the entire text overlay up or down.
- **Tuning:** If the top row of text is cut off, increase this value. If the bottom row is cut off, decrease it.

