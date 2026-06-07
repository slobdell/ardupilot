---
layout: parameter
name: ADSB_LOG
display_name: ADS-B logging
description: 0:no logging, 1:log only special ID, 2:log all
default_value: 1
range: 
units: 
group: ADSB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ADSB/AP_ADSB.cpp
---

# ADS-B logging (ADSB_LOG)

## Description
Controls logging of ADS-B data.

## Tuning & Behavior
*   **Default Value:** 1 (Special ID Only)
*   **Values:** 0:no logging, 1:log only special ID, 2:log all