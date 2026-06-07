---
layout: parameter
name: SIM_CAN_TYPE1
display_name: Simulated CAN 1 Transport Type
description: Selects the backend transport for the first simulated CAN bus (None, MulticastUDP, SocketCAN).
default_value: 1
range: 0 2
units: 
group: SIM
visual_asset_id: can_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated CAN 1 Transport Type (SIM_CAN_TYPE1)

## Description
`SIM_CAN_TYPE1` tells the simulator how to send "CAN Messages" between SITL and other simulated devices (like a DroneCAN GPS).

*   **0: None.**
*   **1: MulticastUDP (Default).** Sends messages over your computer's local network. This is the standard way SITL talks to the "CANDevices" or "UAVCAN GUI Tool."
*   **2: SocketCAN.** Uses the Linux kernel's native CAN bus driver (Linux only).

## Tuning & Behavior
*   **Default Value:** 1.
*   **Recommendation:** Leave at **1** for all standard DroneCAN testing.