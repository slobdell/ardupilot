---
layout: parameter
name: NET_IPADDR2
display_name: IPv4 Address Byte 2
description: The third byte of the static IPv4 address (e.g. 1 in 192.168.1.10).
default_value: 0
range: 0 255
units: 
group: NET
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Networking/AP_Networking_address.cpp#L26
---

# IPv4 Address Byte 2 (NET_IPADDR2)

## Description
`NET_IPADDR2` is the third part of your drone's static network address.

*   **Example:** For an IP of 192.168.**1**.50, set `NET_IPADDR2` to **1**.