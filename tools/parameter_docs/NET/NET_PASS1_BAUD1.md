---
layout: parameter
name: NET_PASS1_BAUD1
display_name: Networking Passthrough BAUD 1
description: The baud rate for Endpoint 1 (only if it is a Serial port).
default_value: 115200
range: 1 4000000
units: bps
group: NET
visual_asset_id: serial_flow_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/networking_passthru.cpp#L43
---

# Networking Passthrough BAUD 1 (NET_PASS1_BAUD1)

## Description
`NET_PASS1_BAUD1` sets the communication speed for the first endpoint in the passthrough bridge.

*   **115200 (Default):** Standard for most telemetry and GPS units.

## Tuning & Behavior
*   **Constraint:** This only applies if `NET_PASS1_EP1` is set to a Serial UART (0-9).
