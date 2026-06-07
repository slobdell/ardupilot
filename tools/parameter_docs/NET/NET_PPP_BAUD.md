---
layout: parameter
name: NET_PPP_BAUD
display_name: PPP Baud Rate
description: Baud rate for the Point-to-Point Protocol (PPP) serial link.
default_value: 57
range: 1 2000
units: 
group: NET
visual_asset_id: serial_baud_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Networking/AP_Networking_PPP.cpp#L100
---

# PPP Baud Rate (NET_PPP_BAUD)

## Description
`NET_PPP_BAUD` sets the speed for the PPP connection. 

This is used when a serial modem (like an LTE modem) is connected to a UART port and the autopilot is acting as a PPP client or gateway.

## Tuning & Behavior
*   **Default Value:** 57 (57600 baud).
*   **Recommendation:** Set to match your modem's baud rate (often **115** or **921**).