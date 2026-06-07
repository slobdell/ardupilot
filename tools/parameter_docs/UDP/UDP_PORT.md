---
layout: parameter
name: UDP_PORT
display_name: DDS UDP port
description: UDP port number for DDS.
default_value: 2019
range: 1 65535
units: 
group: UDP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DDS/AP_DDS_Client.cpp#L120
---

# UDP_PORT: DDS UDP port

## Description
UDP port number for DDS.

## Values
- **Range:** 1 to 65535
- **Default:** 2019

## Description
This parameter sets the destination UDP port for the Data Distribution Service (DDS) interface, which allows ArduPilot to communicate with ROS 2 (Robot Operating System).

- **Function:** The autopilot acts as a DDS client and sends telemetry to an external agent (like Micro-XRCE-DDS-Agent running on a companion computer).
- **Default (2019):** This is the standard port for Micro-XRCE-DDS.
- **Config:** Ensure your companion computer is listening on this same port.

