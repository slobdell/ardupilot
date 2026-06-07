---
layout: parameter
name: CAN_SLCAN_SDELAY
display_name: SLCAN Start Delay
description: Adds a delay before the SLCAN interface starts processing frames.
default_value: 1
range: 0 127
units: s
group: CAN
visual_asset_id: can_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_CANManager/AP_SLCANIface.cpp#L65
---

# SLCAN Start Delay (CAN_SLCAN_SDELAY)

## Description
`CAN_SLCAN_SDELAY` introduces a pause after the SLCAN virtual interface is initialized but before it begins forwarding CAN frames. 

This is primarily a developer or diagnostic feature used when bridging a computer to the DroneCAN bus via the flight controller's USB port (SLCAN mode).

## Tuning & Behavior
*   **Default:** 1 second.
*   **Usage:** Increase this if your GCS or SLCAN tool struggles to connect immediately after the port opens.