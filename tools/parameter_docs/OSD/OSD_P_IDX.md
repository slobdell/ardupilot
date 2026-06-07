---
layout: parameter
name: OSD_P_IDX
display_name: OSD Parameter Slot Index
description: The specific parameter index within the selected group to be tuned.
default_value: 0
range: 0 127
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L68
---

# OSD Parameter Slot Index (OSD_P_IDX)

## Description
`OSD_P_IDX` specifies which individual parameter inside a group (set by [OSD_P_GRP](OSD_P_GRP.html)) is being controlled. 

For example, if the group is "Attitude Control," the index determines if you are adjusting the Roll P, Pitch I, or Yaw D term.

## Tuning & Behavior
*   **Setup:** Use the graphical OSD editor in your GCS to find the correct index for the parameter you wish to tune.