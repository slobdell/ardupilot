---
layout: parameter
name: BRD_RADIO_TESTCH
display_name: Factory test channel
description: Sets the radio to a fixed test channel for factory testing.
default_value: 0
range: 0 8
units: 
group: BRD_RADIO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp
---

# Factory test channel (BRD_RADIO_TESTCH)

## Description
Overrides the normal frequency-hopping behavior to lock the radio onto a specific channel for production testing.