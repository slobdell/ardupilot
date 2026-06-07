---
layout: parameter
name: FS_TEMP_MAX
display_name: Internal Temperature Failsafe
description: The maximum allowed internal temperature (in Celsius) before a failsafe is triggered.
default_value: 70
range: 0 100
units: degC
group: FS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduSub/Parameters.cpp
---

# Internal Temperature Failsafe (FS_TEMP_MAX)

## Description
`FS_TEMP_MAX` protects the vehicle's electronics from overheating.