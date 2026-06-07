---
layout: parameter
name: BRD_RADIO_TESTCH
display_name: Internal Radio Factory Test Channel
description: Locks the integrated radio to a fixed frequency channel for factory testing.
default_value: 0
range: 0 100
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L94
---

# Internal Radio Factory Test Channel (BRD_RADIO_TESTCH)

## Description
`BRD_RADIO_TESTCH` is a production and assembly tool for manufacturers.

It allows a drone's integrated radio to communicate on a fixed, pre-determined frequency channel without going through the standard "Bind" procedure. This allows factory workers to quickly verify that the radio hardware is functioning correctly before shipping.

*   **0: Disabled (Default).** Normal operation with standard binding.
*   **1-100:** Locks the radio to that specific test channel.

## Tuning & Behavior
*   **Default:** 0.
*   **Warning:** **Do not change this.** If this is set to a non-zero value, you will not be able to bind your normal transmitter to the drone.