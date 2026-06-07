---
layout: parameter
name: BRD_RADIO_TSIGCH
display_name: Telemetry RSSI value channel
description: RC Channel to show telemetry RSSI value as received by the transmitter, or zero for disabled.
default_value: 0
range: 0 16
units: 
group: BRD_RADIO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp
---

# Telemetry RSSI value channel (BRD_RADIO_TSIGCH)

## Description
Maps the telemetry signal strength (RSSI) measured by the transmitter back to a virtual RC channel.