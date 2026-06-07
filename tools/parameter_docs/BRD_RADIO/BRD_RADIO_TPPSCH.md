---
layout: parameter
name: BRD_RADIO_TPPSCH
display_name: Telemetry PPS channel
description: RC Channel to show telemetry packets-per-second value, as received at the transmitter.
default_value: 0
range: 0 16
units: 
group: BRD_RADIO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp
---

# Telemetry PPS channel (BRD_RADIO_TPPSCH)

## Description
Maps the telemetry Packet-Per-Second (PPS) rate measured by the transmitter to a virtual RC channel.