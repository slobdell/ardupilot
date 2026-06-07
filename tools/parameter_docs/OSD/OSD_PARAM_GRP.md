---
layout: parameter
name: OSD_PARAM_GRP
display_name: OSD Parameter Group
description: The group key used to identify the parameter family for display and modification on the OSD screen.
default_value: -1
range: -1 1000
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L65
---

# OSD Parameter Group (OSD_PARAM_GRP)

## Description
`OSD_PARAM_GRP` is a technical identifier that helps the OSD system locate the correct group of parameters (e.g. all `ATC_` parameters) to which the tuned setting belongs.