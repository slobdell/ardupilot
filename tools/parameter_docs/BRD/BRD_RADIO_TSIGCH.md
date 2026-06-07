---
layout: parameter
name: BRD_RADIO_TSIGCH
display_name: Internal Radio Telemetry RSSI Channel
description: Maps the telemetry signal strength (as seen by the transmitter) to an RC channel.
default_value: 0
range: 0 16
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L101
---

# Internal Radio Telemetry RSSI Channel (BRD_RADIO_TSIGCH)

## Description
`BRD_RADIO_TSIGCH` reports how "Loudly" the handheld transmitter is hearing the drone. 

This is the telemetry signal strength (RSSI) measured at the ground station/transmitter end. Like [BRD_RADIO_SIGCH](BRD_RADIO_SIGCH.html) (which measures strength at the drone), this parameter maps the ground-side measurement to a virtual RC channel. 

## Tuning & Behavior
*   **Default:** 0.
*   **Significance:** If your drone's SIGCH is high but TSIGCH is low, it means the drone is receiving commands perfectly, but the ground station is struggling to hear the drone's telemetry return signal (often caused by a noisy video transmitter on the drone).