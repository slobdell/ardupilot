---
layout: parameter
name: CAN_D1_UC_S1_NOD
display_name: DroneCAN Serial 1 Node ID
description: The DroneCAN Node ID of the remote serial device (e.g., a GPS or peripheral) to bridge with Serial 1.
default_value: 0
range: 0 127
units: 
group: CAN
visual_asset_id: dronecan_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L160
---

# DroneCAN Serial 1 Node ID (CAN_D1_UC_S1_NOD)

## Description
`CAN_D1_UC_S1_NOD` creates a virtual serial bridge over the CAN bus.

This allows you to connect a Serial GPS to a "Node" (like an AP_Periph adapter) and have ArduPilot talk to it as if it were plugged directly into a UART on the flight controller. This parameter sets the ID of that remote Node.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to the Node ID of your DroneCAN-to-Serial adapter.