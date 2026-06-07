---
layout: parameter
name: NET_MACADDR0
display_name: MAC Address Byte 0
description: The first byte of the hardware MAC address for the Ethernet interface.
default_value: 0
range: 0 255
units: 
group: NET
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Networking/AP_Networking_macaddr.cpp#L14
---

# MAC Address Byte 0 (NET_MACADDR0)

## Description
`NET_MACADDR0` is the first byte of your flight controller's unique physical network ID.

Normally, the flight controller generates a unique MAC address automatically based on its hardware Serial Number. You only need to change this if you have multiple drones on the same network that accidentally have the same MAC address, or if you need to bypass network security filters.

## Tuning & Behavior
*   **Default Value:** 0 (Automatically generated on boot).
*   **Reboot Required:** Yes.