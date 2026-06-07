---
layout: parameter
name: FRSKY_UPLINK_ID
display_name: Uplink sensor id
description: Specifies the SPort sensor ID used for receiving uplink data from the transmitter.
default_value: 13
range: 7 26
units: 
group: FRSKY
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Frsky_Telem/AP_Frsky_Parameters.cpp
---

# Uplink sensor id (FRSKY_UPLINK_ID)

## Description
Defines the logical sensor ID ArduPilot listens to for incoming data from the transmitter over the bidirectional SPort link.
*   **Default Value:** 13