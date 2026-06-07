---
layout: parameter
name: CAN_D1_PROTOCOL2
display_name: CAN Driver 1 Protocol 2
description: Selects a secondary protocol to run alongside the primary protocol on the same CAN driver (e.g., enabling 11-bit support alongside DroneCAN).
default_value: 0
range: 0 12
units: 
group: CAN
visual_asset_id: can_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_CANManager/AP_CANManager_CANDriver_Params.cpp#L41
---

# CAN Driver 1 Protocol 2 (CAN_D1_PROTOCOL2)

## Description
`CAN_D1_PROTOCOL2` allows "Dual Mode" operation on a single CAN bus.

Typically, you can only run one protocol per bus (e.g., DroneCAN). However, some protocols use different message ID lengths (29-bit vs 11-bit) and can coexist. This parameter allows you to enable a secondary 11-bit protocol (like some BMS or ESC telemetry formats) on the same wires as your main DroneCAN network.

*   **0: Disabled.**
*   **10: EFL_ESCORP.** 11-bit ESC telemetry.
