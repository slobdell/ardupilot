---
layout: parameter
name: OSD_PARAM_KEY
display_name: OSD Parameter Key
description: The unique persistent key used to identify a specific parameter for in-flight OSD modification.
default_value: -1
range: -1 65535
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L55
---

# OSD Parameter Key (OSD_PARAM_KEY)

## Description
`OSD_PARAM_KEY` is the unique database identifier for a parameter. This key ensures that even if parameters are added or removed in future firmware versions, the OSD tuning menu continues to point at the correct setting.
