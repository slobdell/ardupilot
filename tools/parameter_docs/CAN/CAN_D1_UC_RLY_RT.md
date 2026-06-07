---
layout: parameter
name: CAN_D1_UC_RLY_RT
display_name: DroneCAN Relay Transmit Rate
description: Maximum transmit rate (in Hz) for relay output messages over DroneCAN.
default_value: 0
range: 0 200
units: Hz
group: CAN
visual_asset_id: dronecan_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L141
---

# DroneCAN Relay Transmit Rate (CAN_D1_UC_RLY_RT)

## Description
`CAN_D1_UC_RLY_RT` sets the heartbeat rate for CAN-based relays.

*   **0:** Send only on change (standard).
*   **Non-Zero:** Periodically re-broadcast the relay state at this rate. This is safer for hardware that needs a "Keep Alive" signal.