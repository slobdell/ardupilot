---
layout: parameter
name: NET_OPTIONS
display_name: Networking Options
description: Bitmask of options to modify networking behavior.
default_value: 0
range: 0 127
units: 
group: NET
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Networking/AP_Networking.cpp#L32
---

# Networking Options (NET_OPTIONS)

## Description
`NET_OPTIONS` enables specialized networking "Bridges" and "Gateways."

*   **Bit 0 (1):** Enable PPP Ethernet Gateway. Allows the drone to share its internet connection (e.g. from a cellular modem) with other devices on the Ethernet bus.
*   **Bit 1 (2):** Enable CAN1 Multicast Endpoint. Forwards DroneCAN traffic to the network so you can use GCS tools over Wifi/Ethernet to tune CAN devices.
*   **Bit 2 (4):** Enable CAN2 Multicast Endpoint.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Enable **Bit 1** if you want to use the "DroneCAN GUI Tool" on your laptop without plugging in a USB cable to the flight controller.