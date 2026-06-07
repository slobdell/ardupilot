---
layout: parameter
name: CAN_P1_BITRATE
display_name: Bitrate of CAN interface 1
description: Bit rate for the first CAN bus.
default_value: 1000000
range: 10000 1000000
units: 
group: CAN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_CANManager/AP_CANIfaceParams.cpp
---

# Bitrate of CAN interface 1 (CAN_P1_BITRATE)

## Description
Defines the communication speed for the first physical CAN bus. All devices on the bus must use the same bitrate to communicate.

## Tuning & Behavior
*   **Default Value:** 1000000 (1 Mbps)
*   **Range:** 10,000 to 1,000,000
*   **1 Mbps is standard for DroneCAN.**
