---
layout: parameter
name: NET_DHCP
display_name: DHCP Enable
description: Enables the DHCP client to automatically obtain an IP address from the network.
default_value: 1
range: 0 1
units: 
group: NET
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Networking/AP_Networking.cpp#L32
---

# DHCP Enable (NET_DHCP)

## Description
`NET_DHCP` tells the autopilot to ask your network router for an IP address automatically.

*   **0 (Static):** You must manually set `NET_IPADDR`, `NET_NETMASK`, and `NET_GWADDR`. Use this for point-to-point connections (e.g. drone directly to laptop).
*   **1 (DHCP):** The drone will get its settings from the router. Use this if the drone is plugged into a home/office network.

## Tuning & Behavior
*   **Default Value:** 1.
*   **Recommendation:** Use **0 (Static)** for mission-critical telemetry to ensure the IP address never changes.