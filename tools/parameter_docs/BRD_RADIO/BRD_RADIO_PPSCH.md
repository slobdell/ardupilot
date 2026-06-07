---
layout: parameter
name: BRD_RADIO_PPSCH
display_name: Packet rate channel
description: RC Channel to show received packet-per-second rate, or zero for disabled.
default_value: 0
range: 0 16
units: 
group: BRD_RADIO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp
---

# Packet rate channel (BRD_RADIO_PPSCH)

## Description
Maps the Packet-Per-Second (PPS) rate to a virtual RC channel.
