---
layout: parameter
name: BRD_SER2_RTSCTS
display_name: Serial 2 flow control
description: Enable flow control on serial 2 (telemetry 2).
default_value: 2
range: 0 3
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Serial 2 flow control (BRD_SER2_RTSCTS)

## Description
Enables hardware flow control for the second telemetry port.
