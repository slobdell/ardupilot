---
layout: parameter
name: BRD_RADIO_STKMD
display_name: Stick input mode
description: This selects between different stick input modes (Mode 1 or Mode 2).
default_value: 2
range: 1 2
units: 
group: BRD_RADIO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp
---

# Stick input mode (BRD_RADIO_STKMD)

## Description
Configures the transmitter stick mapping. Mode 2 (throttle on left) is standard in most regions.

## Tuning & Behavior
*   **Default Value:** 2 (Mode 2)
*   **Values:** 1:Mode1, 2:Mode2
