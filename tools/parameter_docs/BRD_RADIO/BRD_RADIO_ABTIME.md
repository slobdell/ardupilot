---
layout: parameter
name: BRD_RADIO_ABTIME
display_name: Auto-bind time
description: Sets the time with no transmitter packets before the radio starts looking for auto-bind packets.
default_value: 0
range: 0 120
units: s
group: BRD_RADIO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp
---

# Auto-bind time (BRD_RADIO_ABTIME)

## Description
Configures the timeout period of inactivity after which the receiver will automatically enter "binding" mode to search for a new transmitter.
*   **A value of 0 disables auto-bind.**
