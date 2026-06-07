---
layout: parameter
name: BRD_RADIO_PROT
display_name: Radio Protocol
description: Select air protocol for the direct attached radio.
default_value: 0
range: 
units: 
group: BRD_RADIO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp
---

# Radio Protocol (BRD_RADIO_PROT)

## Description
Selects the specific transmission protocol for the direct-attached radio.

## Tuning & Behavior
*   **Default Value:** 0 (Auto)
*   **Values:** 0:Auto, 1:DSM2, 2:DSMX