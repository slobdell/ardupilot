---
layout: parameter
name: RCIN_PORT
display_name: RC Input Port (AP_Periph)
description: Selects the physical serial port index on the AP_Periph node used for the RC receiver.
default_value: 0
range: 0 10
units: 
group: RCIN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/rc_in.cpp#L60
---

# RC Input Port (AP_Periph) (RCIN_PORT)

## Description
`RCIN_PORT` specifies which UART connector on your peripheral hardware is plugged into the RC receiver.

This is primarily used on **AP_Periph** CAN nodes that are acting as "Remote RC Ports." It allows the node to know which serial hardware to initialize for protocol detection.

## Tuning & Behavior
*   **Default:** 0.
*   **Setup:** Refer to the hardware manual for your CAN node (e.g. Matek L431) to find the correct port number.
*   **Reboot Required:** Yes.