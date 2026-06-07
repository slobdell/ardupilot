---
layout: parameter
name: OSD_W_EN
display_name: OSD Element Enable (General)
description: Enables or disables a specific element on the OSD screen.
default_value: 0
range: 0 1
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_Setting.cpp#L32
---

# OSD Element Enable (OSD_W_EN)

## Description
`OSD_W_EN` (usually appearing as `OSDx_WIDGET_EN`) is the master toggle for showing or hiding information on your video feed.

Each piece of data (Altitude, Voltage, Sats) has its own enable parameter. If set to 1, the element is drawn on the screen at its configured X and Y coordinates. If set to 0, that space on the screen remains clear.

*   **0: Disabled.**
*   **1: Enabled.**

## Tuning & Behavior
*   **Recommendation:** Enable only the parameters you need for your current mission to keep the video feed uncluttered. 
*   **Instant Update:** Changes made via MAVLink (GCS) typically appear on the screen immediately without requiring a reboot.