---
layout: parameter
name: NET_IPADDR1
display_name: IPv4 Address Byte 1
description: The second byte of the static IPv4 address (e.g. 168 in 192.168.1.10).
default_value: 0
range: 0 255
units: 
group: NET
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Networking/AP_Networking_address.cpp#L21
---

# IPv4 Address Byte 1 (NET_IPADDR1)

## Description
`NET_IPADDR1` is the second part of your drone's static network address.

*   **Example:** For an IP of 192.**168**.1.50, set `NET_IPADDR1` to **168**.