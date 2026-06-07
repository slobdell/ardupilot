---
layout: parameter
name: OSD_PARAM_X
display_name: OSD Parameter X Position
description: The horizontal position of a parameter editing field on the OSD screen.
default_value: 0
range: 0 59
units: 
group: OSD
visual_asset_id: osd_panel_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD_Setting.cpp#L32
---

# OSD Parameter X Position (OSD_PARAM_X)

## Description
`OSD_PARAM_X` sets the horizontal coordinate for a parameter editing element on the OSD display.

This is part of the in-flight parameter tuning system, allowing you to move where specific PID gains or settings appear when you enter the OSD menu.

## Tuning & Behavior
*   **0:** Left edge.
*   **High Value:** Right edge.