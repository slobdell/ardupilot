---
layout: parameter
name: NET_P1_PORT
display_name: Network Port 1 Number
description: The TCP or UDP port number for the virtual network serial port 1.
default_value: 0
range: 1 65535
units: 
group: NET
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Networking/AP_Networking_port.cpp#L48
---

# Network Port 1 Number (NET_P1_PORT)

## Description
`NET_P1_PORT` defines the "Door Number" for network traffic.

## Tuning & Behavior
*   **Default Value:** 0.
*   **MAVLink Standard:** Set to **14550** or **14551** for standard ground station compatibility.
