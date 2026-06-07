---
layout: parameter
name: OSD_P_GRP
display_name: OSD Parameter Slot Group
description: The group ID for the parameter being tuned in this OSD slot.
default_value: 0
range: 0 32767
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L74
---

# OSD Parameter Slot Group (OSD_P_GRP)

## Description
`OSD_P_GRP` identifies the "Class" or "Category" of the parameter you want to tune in an in-flight menu. 

Every parameter in ArduPilot has a group ID. This is typically configured using a GCS (like Mission Planner's OSD setup screen) rather than entered manually, but this parameter stores that selection.

*   **0:** Root/Global parameters.
*   **Other Values:** Internal IDs for specific libraries (e.g. 1 for Attitude Control).

## Tuning & Behavior
*   **Setup:** This should be used in combination with [OSD_P_IDX](OSD_P_IDX.html) to target a specific parameter. 
*   **Ease of Use:** It is highly recommended to use the graphical OSD editor in your GCS to set these values.