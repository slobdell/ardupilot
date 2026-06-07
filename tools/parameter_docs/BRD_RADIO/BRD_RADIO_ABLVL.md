---
layout: parameter
name: BRD_RADIO_ABLVL
display_name: Auto-bind level
description: Sets the minimum RSSI of an auto-bind packet for it to be accepted.
default_value: 0
range: 0 31
units: 
group: BRD_RADIO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp
---

# Auto-bind level (BRD_RADIO_ABLVL)

## Description
Security threshold for auto-binding. Higher values require the transmitter to be very close to the receiver during the auto-bind process, preventing accidental binding to other transmitters nearby.
