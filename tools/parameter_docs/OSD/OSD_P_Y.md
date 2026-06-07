---
layout: parameter
name: OSD_P_Y
display_name: OSD Parameter Slot Y Position
description: The vertical coordinate (row) for the parameter tuning slot.
default_value: 0
range: 0 21
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L53
---

# OSD Parameter Slot Y Position (OSD_P_Y)

## Description
`OSD_P_Y` defines the vertical position of an in-flight tuning slot. 

Since each tuning screen typically displays a list of parameters, these values are usually staggered (e.g., Slot 1 at `Y=2`, Slot 2 at `Y=4`) to create a clear vertical menu.

## Tuning & Behavior
*   **Analog Height:** ~16 rows.
*   **Digital Height:** ~22 rows.
*   **Note:** Ensure you don't overlap your parameter slots with permanent flight widgets like the Artificial Horizon or Battery voltage.