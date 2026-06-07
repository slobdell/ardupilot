---
layout: parameter
name: OSD_W_Y
display_name: OSD Element Y Position
description: The vertical coordinate (row) for the OSD element.
default_value: 0
range: 0 21
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_Setting.cpp#L46
---

# OSD Element Y Position (OSD_W_Y)

## Description
`OSD_W_Y` defines the vertical position of an OSD widget.

*   **For Analog (PAL/NTSC):** The screen is typically 16 rows high.
*   **For Digital (MSP):** The screen can be up to 22 rows high.
*   **0:** Top edge.
*   **Max:** Bottom edge.

## Tuning & Behavior
*   **Instant Update:** Changes appear immediately on the screen.
*   **Validation:** If an element disappears, check that the Y value is not higher than your OSD's maximum height.