---
layout: parameter
name: NET_ENABLE
display_name: Networking Enable
description: Master switch to enable/disable the onboard networking stack (Ethernet, PPP).
default_value: 0
range: 0 1
units: 
group: NET
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Networking/AP_Networking.cpp#L32
---

# Networking Enable (NET_ENABLE)

## Description
`NET_ENABLE` activates the IP (Internet Protocol) communications stack on the flight controller. 

If your flight controller has an Ethernet port (like the Cube Orange with an ADS-B carrier board or the Holybro Pixhawk 6X), this parameter must be set to 1 to enable MAVLink over UDP or TCP.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Enabled.
*   **Reboot Required:** Yes.
