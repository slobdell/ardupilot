---
layout: parameter
name: CAN_MIRROR_PORTS
display_name: CAN Port Mirroring
description: Enables mirroring of traffic between two CAN ports (bridge mode).
default_value: 0
range: 0 3
units: 
group: CAN
visual_asset_id: can_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/Parameters.cpp#L671
---

# CAN Port Mirroring (CAN_MIRROR_PORTS)

## Description
`CAN_MIRROR_PORTS` turns the flight controller (or AP_Periph node) into a CAN Bridge.

Any message received on one port is instantly copied and sent out the other port. This is useful for creating a "Pass-Through" node or daisy-chaining buses that are electrically separate.

*   **Bitmask:**
    *   Bit 0: Port 1
    *   Bit 1: Port 2

## Tuning & Behavior
*   **Default:** 0 (Disabled).
*   **Warning:** Both ports must be set to the same bitrate.
*   **Danger:** Do not create a loop (connecting Port 1 to Port 2 externally) while this is enabled, or you will create a "Broadcast Storm" that floods the bus and crashes the network.