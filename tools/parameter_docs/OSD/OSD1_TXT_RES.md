---
layout: parameter
name: OSD1_TXT_RES
display_name: OSD Screen Resolution (Instance 1)
description: Sets the character grid resolution for this screen. Primarily for digital OSDs (MSP DisplayPort).
default_value: 0
range: 0 2
units: 
group: OSD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_Screen.cpp#L1077
---

# OSD Screen Resolution (OSD1_TXT_RES)

## Description
`OSD1_TXT_RES` defines the pixel/character density of the display.

While analog OSDs are fixed in resolution, digital systems like **DJI** or **Avatar** can support higher densities. This parameter allows you to choose between standard and high-definition layouts.

*   **0: 30x16.** Standard Definition (Analog compatibility).
*   **1: 50x18.** High Definition.
*   **2: 60x22.** Ultra-High Definition.

## Tuning & Behavior
*   **Significance:** Only applicable to digital OSD backends (MSP DisplayPort). Changing this will rearrange your widgets because the coordinate system (X/Y) depends on the grid size.