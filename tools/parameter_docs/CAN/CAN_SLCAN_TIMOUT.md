---
layout: parameter
name: CAN_SLCAN_TIMOUT
display_name: SLCAN Timeout
description: Timeout in seconds for the SLCAN bridge.
default_value: 0
range: 
units: s
group: CAN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_CANManager/AP_SLCANIface.cpp
---

# SLCAN Timeout (CAN_SLCAN_TIMOUT)

## Description
The inactivity period after which the SLCAN bridge is automatically closed.