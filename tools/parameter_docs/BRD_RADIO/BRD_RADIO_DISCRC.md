---
layout: parameter
name: BRD_RADIO_DISCRC
display_name: Disable receive CRC
description: Disable receive CRC (for debugging purposes only).
default_value: 0
range: 0 1
units: 
group: BRD_RADIO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp
---

# Disable receive CRC (BRD_RADIO_DISCRC)

## Description
Disables the Cyclical Redundancy Check (CRC) for incoming radio packets.
*   **WARNING: Should only be used for debugging. Disabling CRC allows corrupted data to be processed as valid commands.**
