---
layout: parameter
name: OSD_PARAM_IDX
display_name: OSD Parameter Index
description: The internal index used to identify the specific parameter to be displayed and modified on the OSD screen.
default_value: -1
range: -1 255
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L60
---

# OSD Parameter Index (OSD_PARAM_IDX)

## Description
`OSD_PARAM_IDX` is a technical identifier used by the OSD system to find the correct parameter in the flight controller's memory. It is usually set automatically when you configure the OSD using a tool like Mission Planner.