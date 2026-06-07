---
layout: parameter
name: OSD_FONT
display_name: OSD Font
description: Selects the font table to use for the on-screen display.
default_value: 0
range: 0 5
units: 
group: OSD
visual_asset_id: osd_font_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L100
---

# OSD Font (OSD_FONT)

## Description
`OSD_FONT` allows you to change the visual style of the text and icons on your video feed.

Most flight controllers store multiple font sheets in their flash memory.

*   **0:** Default (Clarity / Betaflight style).
*   **1:** Bold.
*   **2:** Digital.
*   **3:** Mavlink (Data heavy).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Note:** If you see garbled characters or Chinese symbols instead of battery icons, your font sheet might be corrupted or incompatible with the firmware version. Upload a new font via the GCS.
