---
layout: parameter
name: ESC_CMD_TIMO
display_name: ESC Command Timeout
description: The maximum time (in ms) to wait for a response from a smart ESC before declaring a timeout.
default_value: 100
range: 0 1000
units: ms
group: ESC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ESC_Telem/AP_ESC_Telem.cpp
---

# ESC Command Timeout (ESC_CMD_TIMO)

## Description
`ESC_CMD_TIMO` defines how long the autopilot will wait for a response when communicating with "Smart" ESCs (like DroneCAN or serial ESCs).