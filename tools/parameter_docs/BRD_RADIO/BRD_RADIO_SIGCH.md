---
layout: parameter
name: BRD_RADIO_SIGCH
display_name: RSSI signal strength channel
description: RC Channel to show received RSSI signal strength, or zero for disabled.
default_value: 0
range: 0 16
units: 
group: BRD_RADIO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp
---

# RSSI signal strength channel (BRD_RADIO_SIGCH)

## Description
Maps the RSSI (Signal Strength) value to a virtual RC channel, allowing it to be monitored by the GCS or used in other logic.