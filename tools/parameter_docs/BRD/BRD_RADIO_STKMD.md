---
layout: parameter
name: BRD_RADIO_STKMD
display_name: Internal Radio Stick Mode
description: Selects between Mode 1 and Mode 2 transmitter stick layouts.
default_value: 2
range: 1 2
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L87
---

# Internal Radio Stick Mode (BRD_RADIO_STKMD)

## Description
`BRD_RADIO_STKMD` defines which sticks on your transmitter control which flight axes.

*   **Mode 1:** Throttle and Roll on the right stick. Pitch and Yaw on the left stick.
*   **Mode 2 (Default):** Throttle and Yaw on the left stick. Pitch and Roll on the right stick. (Standard for most of the world).

## Tuning & Behavior
*   **Default:** 2.
*   **Usage:** Only change this if you are a pilot trained in Mode 1 flight. This parameter is sent to the handheld transmitter to reconfigure its internal mixing.