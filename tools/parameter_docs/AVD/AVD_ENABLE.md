---
layout: parameter
name: AVD_ENABLE
display_name: Enable Avoidance using ADSB
description: Enable Avoidance using ADSB.
default_value: 0
range: 0 1
units: 
group: AVD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Avoidance/AP_Avoidance.cpp
---

# Enable Avoidance using ADSB (AVD_ENABLE)

## Description
Global master switch for the ADS-B based collision avoidance system.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Values:** 0:Disabled, 1:Enabled
*   **Requires a functional ADS-B receiver (see ADSB_TYPE).**
