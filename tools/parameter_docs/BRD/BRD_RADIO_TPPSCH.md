---
layout: parameter
name: BRD_RADIO_TPPSCH
display_name: Internal Radio Telemetry PPS Channel
description: Maps the telemetry packet-per-second (PPS) rate (as seen by the transmitter) to an RC channel.
default_value: 0
range: 0 16
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L108
---

# Internal Radio Telemetry PPS Channel (BRD_RADIO_TPPSCH)

## Description
`BRD_RADIO_TPPSCH` provides the "Uplink" counterpart to [BRD_RADIO_PPSCH](BRD_RADIO_PPSCH.html). 

It reports how many telemetry packets the handheld transmitter is successfully receiving from the drone every second. This value is transmitted back to the drone and mapped to a virtual RC channel. Monitoring both PPS and TPPS allows you to identify if a signal problem is one-way (e.g., a noisy VTX drowning out telemetry) or two-way (range limit).

## Tuning & Behavior
*   **Default:** 0.
*   **Setup:** Map this to an RC channel and monitor it on your OSD to verify that your telemetry link is stable during flight.