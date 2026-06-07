---
layout: parameter
name: BRD_RADIO_TXPOW
display_name: Telemetry Transmit power
description: Set telemetry transmit power (from 1 to 8) for telemetry packets sent from the RX to the TX.
default_value: 8
range: 1 8
units: 
group: BRD_RADIO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp
---

# Telemetry Transmit power (BRD_RADIO_TXPOW)

## Description
Sets the transmission power level for telemetry data sent back to the transmitter.