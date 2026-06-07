---
layout: parameter
name: BRD_RADIO_ABLVL
display_name: Internal Radio Auto-Bind RSSI Level
description: Minimum signal strength (RSSI) required to accept an auto-bind packet.
default_value: 0
range: 0 31
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L136
---

# Internal Radio Auto-Bind RSSI Level (BRD_RADIO_ABLVL)

## Description
`BRD_RADIO_ABLVL` is a security filter for the [BRD_RADIO_ABTIME](BRD_RADIO_ABTIME.html) feature. 

It defines how close a transmitter must be before the drone will allow itself to be bound to it. By requiring a high signal strength (high RSSI), it ensures that your drone only binds to the transmitter you are holding in your hand, rather than someone else's transmitter in a nearby field.

## Tuning & Behavior
*   **Default:** 0 (Any strength accepted - Least secure).
*   **Recommendation:** Set this to a value that requires the transmitter to be within **1-2 meters** of the drone during binding.
*   **Usage:** Only used when the radio is actively in Auto-Bind mode.