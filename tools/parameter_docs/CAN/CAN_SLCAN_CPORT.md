---
layout: parameter
name: CAN_SLCAN_CPORT
display_name: SLCAN CAN port
description: Selects the CAN port to be used for SLCAN (Serial Link over CAN) bridge.
default_value: 0
range: 0 3
units: 
group: CAN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_CANManager/AP_SLCANIface.cpp
---

# SLCAN CAN port (CAN_SLCAN_CPORT)

## Description
Defines which physical CAN bus is mapped to the SLCAN bridge for direct hardware access (e.g., using UAVCAN GUI Tool).