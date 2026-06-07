---
layout: parameter
name: OSD_PARAM_MIN
display_name: OSD Parameter Minimum Value
description: The minimum allowed value for the parameter being adjusted via the OSD tuning menu.
default_value: 0
range: -10000 10000
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L70
---

# OSD Parameter Minimum Value (OSD_PARAM_MIN)

## Description
`OSD_PARAM_MIN` sets a safety floor for in-flight tuning.

When you are adjusting a parameter (like a PID gain) using your transmitter sticks and the OSD menu, this value prevents you from accidentally setting the parameter too low, which could make the drone unstable or unable to fly.