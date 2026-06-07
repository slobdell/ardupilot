---
layout: parameter
name: NET_PASS1_EP1
display_name: Networking Passthrough Endpoint 1
description: Selects the source/destination for the first side of the passthrough bridge. Can be a Serial UART, a Network port, or a CAN port.
default_value: -1
range: -1 59
units: 
group: NET
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/networking_passthru.cpp#L33
---

# Networking Passthrough Endpoint 1 (NET_PASS1_EP1)

## Description
`NET_PASS1_EP1` defines the first "Socket" in your data bridge.

You can select from a wide variety of physical and virtual ports. Data received on Endpoint 1 is sent to Endpoint 2, and vice versa.

## Values
*   **-1:** Disabled.
*   **0-9:** Physical Serial Ports (Serial0 is usually USB).
*   **21-29:** Network Ports (UDP/TCP sockets configured in `NET_Pn_`).
*   **41-49:** CAN1 Virtual Ports.
*   **51-59:** CAN2 Virtual Ports.

## Tuning & Behavior
*   **Reboot Required:** Yes.
*   **Example:** To bridge a TCP socket (Network Port 1) to a Serial GPS (Serial 3), set `EP1 = 21` and `EP2 = 3`.