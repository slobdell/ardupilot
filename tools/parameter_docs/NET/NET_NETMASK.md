---
layout: parameter
name: NET_NETMASK
display_name: Network Mask
description: The subnet mask for the static IP configuration, expressed as a CIDR bitcount.
default_value: 24
range: 0 32
units: bits
group: NET
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Networking/AP_Networking.cpp#L32
---

# Network Mask (NET_NETMASK)

## Description
`NET_NETMASK` defines the size of your local network. It uses CIDR notation (the number of bits set to 1).

*   **24:** Equivalent to `255.255.255.0`. Standard for most home networks.
*   **16:** Equivalent to `255.255.0.0`. 

## Tuning & Behavior
*   **Default Value:** 24.