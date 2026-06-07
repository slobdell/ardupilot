---
layout: parameter
name: BRD_ALT_CONFIG
display_name: Alternative HW config
description: Select an alternative hardware configuration. A value of zero selects the default configuration for this board.
default_value: 0
range: 0 10
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Alternative HW config (BRD_ALT_CONFIG)

## Description
Selects pre-defined alternative pin assignments or hardware options for specific boards. Refer to your board's documentation for valid values.