---
layout: parameter
name: CAN_D1_UC_S1_PRO
display_name: DroneCAN Serial 1 Protocol
description: Selects the protocol used on the DroneCAN Serial 1 bridge.
default_value: -1
range: -1 60
units: 
group: CAN
visual_asset_id: serial_protocol_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L180
---

# DroneCAN Serial 1 Protocol (CAN_D1_UC_S1_PRO)

## Description
`CAN_D1_UC_S1_PRO` defines what language the serial bridge speaks. It uses the standard `SERIAL_PROTOCOL` values (e.g., 5 for GPS, 2 for MAVLink).

## Tuning & Behavior
*   **Default Value:** -1 (Same as Serial Manager).