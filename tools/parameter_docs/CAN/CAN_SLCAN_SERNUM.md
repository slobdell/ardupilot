---
layout: parameter
name: CAN_SLCAN_SERNUM
display_name: SLCAN Serial Port
description: Selects the serial port number to be used for the SLCAN bridge.
default_value: -1
range: 
units: 
group: CAN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_CANManager/AP_SLCANIface.cpp
---

# SLCAN Serial Port (CAN_SLCAN_SERNUM)

## Description
Specifies the USB or hardware serial port instance that serves as the bridge to the CAN bus selected in CAN_SLCAN_CPORT.