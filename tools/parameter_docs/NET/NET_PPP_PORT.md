---
layout: parameter
name: NET_PPP_PORT
display_name: PPP Serial Port
description: The serial port index used for the PPP connection.
default_value: 0
range: 0 10
units: 
group: NET
visual_asset_id: brd_io_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Networking/AP_Networking_PPP.cpp#L100
---

# PPP Serial Port (NET_PPP_PORT)

## Description
`NET_PPP_PORT` selects which physical UART (TELEM port) is connected to the PPP modem.

*   **0:** Serial 0 (USB).
*   **1:** Serial 1 (Telem 1).