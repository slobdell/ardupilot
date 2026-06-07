---
layout: parameter
name: ADSB_BAUDRATE
display_name: "ADSB serial baudrate"
description: "Baudrate for the ADSB UART"
default_value: 57600
range: 
units: ""
group: ADSB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L366
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# ADSB serial baudrate (ADSB_BAUDRATE)

## Description
This parameter sets the communication speed (baud rate) for the serial port on the DroneCAN peripheral that is connected to an ADS-B receiver (like the uAvionix PingRX).

## The Mathematics
Standard Serial Baud Rates (57600, 115200, etc.).

## The Engineer's View
Defined in `Tools/AP_Periph/Parameters.cpp`. Configures the UART attached to the ADS-B driver stack on the peripheral node.

## Tuning & Behavior
*   **Default Value:** 57600
*   **Match Hardware:** Must match the fixed baud rate of your ADS-B receiver.