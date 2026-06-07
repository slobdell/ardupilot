---
layout: parameter
name: OSD_W_X
display_name: OSD Element X Position
description: The horizontal coordinate (column) for the OSD element.
default_value: 0
range: 0 59
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_Setting.cpp#L39
---

# OSD Element X Position (OSD_W_X)

## Description
`OSD_W_X` defines the horizontal position of an OSD widget.

*   **For Analog (PAL/NTSC):** The screen is typically 30 columns wide.
*   **For Digital (MSP):** The screen can be up to 60 columns wide depending on the resolution.
*   **0:** Left edge.
*   **Max:** Right edge.

## Tuning & Behavior
*   **Instant Update:** Changes appear immediately on the screen.
*   **Validation:** If an element disappears, check that the X value is not higher than your OSD's maximum width.