---
layout: parameter
name: OSD_P_X
display_name: OSD Parameter Slot X Position
description: The horizontal coordinate (column) for the parameter tuning slot.
default_value: 2
range: 0 59
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L46
---

# OSD Parameter Slot X Position (OSD_P_X)

## Description
`OSD_P_X` defines the horizontal position of an in-flight tuning slot. 

By default, these slots are aligned on the left side of the screen (`X=2`) to allow space for the parameter name and its current value to be displayed.

## Tuning & Behavior
*   **PAL/NTSC Width:** ~30 columns.
*   **Digital Width:** ~60 columns.
*   **Recommendation:** Keep these aligned in a column for readability.