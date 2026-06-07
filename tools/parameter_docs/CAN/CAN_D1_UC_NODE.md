---
layout: parameter
name: CAN_D1_UC_NODE
display_name: DroneCAN Node ID (Driver 1)
description: The Node ID for the autopilot on the DroneCAN bus.
default_value: 0
range: 0 125
units: 
group: CAN
visual_asset_id: can_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L100
---

# DroneCAN Node ID (CAN_D1_UC_NODE)

## Description
`CAN_D1_UC_NODE` sets the autopilot's own address on the DroneCAN network.

Every device on the bus (GPS, ESC, Battery) needs a unique ID. 

*   **0 (Default):** Dynamic allocation. The autopilot will claim the first available ID (usually 10).
*   **1-125:** Fixed ID.

## Tuning & Behavior
*   **Recommendation:** Leave at **0** for most setups. If you have a complex network with many devices and want to enforce a strict ID map, set this to a fixed value (e.g. 10).
