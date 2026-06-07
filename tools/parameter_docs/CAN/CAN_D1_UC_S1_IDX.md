---
layout: parameter
name: CAN_D1_UC_S1_IDX
display_name: DroneCAN Serial 1 Bridge Index
description: The serial port index (SERIALx) to bridge with the first DroneCAN serial stream.
default_value: -1
range: -1 10
units: 
group: CAN
visual_asset_id: dronecan_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L160
---

# DroneCAN Serial 1 Bridge Index (CAN_D1_UC_S1_IDX)

## Description
`CAN_D1_UC_S1_IDX` links a specific autopilot serial manager instance to the CAN bridge.

If you want the device on the other end of the CAN bus to appear as "Serial 1" on your flight controller, set this to 1. 

## Tuning & Behavior
*   **Default Value:** -1 (Disabled).