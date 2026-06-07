---
layout: parameter
name: NET_IPADDR0
display_name: IPv4 Address Byte 0
description: The first byte of the static IPv4 address (e.g. 192 in 192.168.1.10).
default_value: 0
range: 0 255
units: 
group: NET
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Networking/AP_Networking_address.cpp#L16
---

# IPv4 Address Byte 0 (NET_IPADDR0)

## Description
`NET_IPADDR0` is the first part of your drone's static network address.

If you are using an Ethernet-capable flight controller (like the Cube Orange with an Ethernet carrier) and have disabled DHCP (`NET_DHCP = 0`), you must manually set the IP address using the `NET_IPADDR` parameters.

*   **Example:** For an IP of **192**.168.1.50, set `NET_IPADDR0` to **192**.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Reboot Required:** Yes.
*   **Constraint:** Only active if `NET_DHCP` is set to 0.