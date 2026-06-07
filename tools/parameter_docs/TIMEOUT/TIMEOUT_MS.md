---
layout: parameter
name: TIMEOUT_MS
display_name: DDS ping timeout
description: The time in milliseconds the DDS client will wait for a response from the XRCE agent before reattempting.
default_value: 1000
range: 1 10000
units: ms
group: TIMEOUT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DDS/AP_DDS_Client.cpp#L144
---

# TIMEOUT_MS: DDS ping timeout

## Description
The time in milliseconds the DDS client will wait for a response from the XRCE agent before reattempting.

## Values
- **Range:** 1 to 10000
- **Units:** ms
- **Default:** 1000

## Description
This parameter manages the connection timeout for the **DDS (Data Distribution Service)** interface, typically used for ROS 2 integration.

- **Function:** The autopilot (DDS Client) periodically pings the companion computer (XRCE Agent). If no response is received within this time limit, the client assumes the connection is lost and attempts to reconnect.
- **Usage:** Adjust this based on the latency and reliability of your serial or Ethernet link to the companion computer.
- **Tuning:** If you have a slow or congested network, increase this to prevent spurious disconnects.

