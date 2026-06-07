---
layout: parameter
name: DID_CANDRIVER
display_name: DroneCAN driver number
description: DroneCAN driver index for Remote ID messages. 0 to disable DroneCAN.
default_value: 0
range: 0 2
units: 
group: DID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OpenDroneID/AP_OpenDroneID.cpp
---

# DroneCAN driver number (DID_CANDRIVER)

## Description
Selects which CAN driver instance should be used to transmit Remote ID data to a DroneCAN-capable transponder.