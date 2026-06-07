---
layout: parameter
name: ESC_TELEM_PORT
display_name: ESC Telemetry Serial Port
description: This is the serial port number where SERIALx_PROTOCOL will be set to ESC Telemetry.
default_value: -1
range: 0 10
units: 
group: ESC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/Parameters.cpp
---

# ESC Telemetry Serial Port (ESC_TELEM_PORT)

## Description
Specifies the physical serial port on the AP_Periph node used to read telemetry data from the ESCs.