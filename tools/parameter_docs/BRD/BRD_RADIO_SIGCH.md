---
layout: parameter
name: BRD_RADIO_SIGCH
display_name: Internal Radio RSSI Channel
description: Selects an RC channel to output the radio signal strength (RSSI).
default_value: 0
range: 0 16
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L52
---

# Internal Radio RSSI Channel (BRD_RADIO_SIGCH)

## Description
`BRD_RADIO_SIGCH` allows you to monitor the health of your wireless link by injecting the RSSI (Received Signal Strength Indicator) into a virtual RC channel.

This allows standard OSDs and Ground Control Stations to display the signal strength of the integrated SPI radio just like a traditional receiver.

*   **0:** Disabled.
*   **1-16:** The RC channel number where RSSI data will be injected (usually set to channel 8 or 16).

## Tuning & Behavior
*   **Default:** 0.
*   **Setup:** If you set this to 16, ensure your OSD or GCS is configured to look at Channel 16 for RSSI information.