---
layout: parameter
name: CAN_D1_UC_ESC_OF
display_name: DroneCAN ESC Offset
description: Offset for ESC numbering in DroneCAN ESC RawCommand messages.
default_value: 0
range: 0 18
units: 
group: CAN
visual_asset_id: dronecan_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L135
---

# DroneCAN ESC Offset (CAN_D1_UC_ESC_OF)

## Description
`CAN_D1_UC_ESC_OF` shifts the motor numbering on the CAN bus.

If you have 8 motors, but your CAN ESCs are programmed as IDs 9 through 16, you can use this offset to align the autopilot's internal motor 1 with CAN ID 9.

## Tuning & Behavior
*   **Default Value:** 0.