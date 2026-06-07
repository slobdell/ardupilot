---
layout: parameter
name: DID_MAVPORT
display_name: MAVLink serial port
description: Serial port number to send OpenDroneID MAVLink messages to. Can be -1 if using DroneCAN.
default_value: -1
range: -1 6
units: 
group: DID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OpenDroneID/AP_OpenDroneID.cpp
---

# MAVLink serial port (DID_MAVPORT)

## Description
Specifies the physical serial port connected to the Remote ID broadcast hardware (transponder).
*   **-1 disables serial output (e.g., if using DroneCAN).**