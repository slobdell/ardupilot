---
layout: parameter
name: ADSB_OPTIONS
display_name: ADS-B Options
description: Options for emergency failsafe codes and device capabilities.
default_value: 0
range: 
units: 
group: ADSB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ADSB/AP_ADSB.cpp
---

# ADS-B Options (ADSB_OPTIONS)

## Description
Configuration options for ADS-B behavior and failsafes.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:** 0:Ping200X Send GPS, 1:Squawk 7400 on RC failsafe, 2:Squawk 7400 on GCS failsafe, 3:Sagetech MXS use External Config
