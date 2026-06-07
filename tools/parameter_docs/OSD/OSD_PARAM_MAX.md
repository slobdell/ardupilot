---
layout: parameter
name: OSD_PARAM_MAX
display_name: OSD Parameter Maximum Value
description: The maximum allowed value for the parameter being adjusted via the OSD tuning menu.
default_value: 100
range: -10000 10000
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L75
---

# OSD Parameter Maximum Value (OSD_PARAM_MAX)

## Description
`OSD_PARAM_MAX` sets a safety ceiling for in-flight tuning. It prevents you from accidentally increasing a gain to a level that causes violent oscillations or mechanical failure.