---
layout: parameter
name: BRD_SERIAL_NUM
display_name: User-defined serial number
description: User-defined serial number of this vehicle. It can be any arbitrary number and has no effect on the autopilot logic.
default_value: 0
range: -8388608 8388607
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# User-defined serial number (BRD_SERIAL_NUM)

## Description
Allows users to assign a unique ID number to their aircraft. This is useful for fleet management and identifying specific airframes in log files.