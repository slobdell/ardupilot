---
layout: parameter
name: NET_P1_PROTOCOL
display_name: Network Port 1 Protocol
description: Selects the protocol used on the first virtual network serial port.
default_value: 0
range: 0 60
units: 
group: NET
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Networking/AP_Networking_port.cpp#L40
---

# Network Port 1 Protocol (NET_P1_PROTOCOL)

## Description
`NET_P1_PROTOCOL` identifies the "Language" spoken on the virtual network port. This uses the same values as the physical `SERIALx_PROTOCOL` parameters.

*   **2:** MAVLink 2 (Default for most GCS).
*   **5:** GPS.
*   **20:** NMEA Output.

## Tuning & Behavior
*   **Default Value:** 0 (None).
*   **Recommendation:** Set to **2** for GCS telemetry.
