---
layout: parameter
name: FRSKY_DNLINK_ID
display_name: Default downlink sensor id
description: Specifies the SPort sensor ID used for the primary downlink telemetry data.
default_value: 27
range: 7 27
units: 
group: FRSKY
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Frsky_Telem/AP_Frsky_Parameters.cpp
---

# Default downlink sensor id (FRSKY_DNLINK_ID)

## Description
Defines the logical sensor ID that ArduPilot uses to transmit data over the FrSky SmartPort (SPort) downlink.
*   **Default Value:** 27