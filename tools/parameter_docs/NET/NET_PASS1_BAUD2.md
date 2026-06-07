---
layout: parameter
name: NET_PASS1_BAUD2
display_name: Networking Passthrough BAUD 2
description: The baud rate for Endpoint 2 (only if it is a Serial port).
default_value: 115200
range: 1 4000000
units: bps
group: NET
visual_asset_id: serial_flow_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/networking_passthru.cpp#L48
---

# Networking Passthrough BAUD 2 (NET_PASS1_BAUD2)

## Description
`NET_PASS1_BAUD2` sets the communication speed for the second endpoint.

See [NET_PASS1_BAUD1](NET_PASS1_BAUD1.html) for details.
