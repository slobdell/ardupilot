---
layout: parameter
name: BRD_RADIO_DEBUG
display_name: Internal Radio Debug Level
description: Sets the verbosity of diagnostic messages for the integrated SPI radio.
default_value: 0
range: 0 4
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L38
---

# Internal Radio Debug Level (BRD_RADIO_DEBUG)

## Description
`BRD_RADIO_DEBUG` is a troubleshooting tool for flight controllers with integrated SPI-based radio receivers (like SkyViper).

It controls how much information about the wireless link (packet loss, signal timing, binding status) is sent to the flight controller's internal console or MAVLink GCS.

*   **0: Disabled (Default).**
*   **1-4:** Increasing levels of diagnostic data.

## Tuning & Behavior
*   **Warning:** Higher debug levels can flood the communication ports and may cause slight performance hits. Only enable this if you are actively diagnosing a "No RC Link" issue with an integrated radio.