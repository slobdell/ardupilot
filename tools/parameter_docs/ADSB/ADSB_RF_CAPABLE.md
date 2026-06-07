---
layout: parameter
name: ADSB_RF_CAPABLE
display_name: RF capabilities
description: Describes your hardware RF In/Out capabilities.
default_value: 0
range: 
units: 
group: ADSB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ADSB/AP_ADSB.cpp
---

# RF capabilities (ADSB_RF_CAPABLE)

## Description
Description of the transceiver's hardware RF capabilities.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:** 0:UAT_in, 1:1090ES_in, 2:UAT_out, 3:1090ES_out