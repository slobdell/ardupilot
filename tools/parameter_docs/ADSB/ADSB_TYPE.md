---
layout: parameter
name: ADSB_TYPE
display_name: ADSB Type
description: Type of ADS-B hardware for ADSB-in and ADSB-out configuration and operation. If any type is selected then MAVLink based ADSB-in messages will always be enabled.
default_value: 0
range: 
units: 
group: ADSB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ADSB/AP_ADSB.cpp
---

# ADSB Type (ADSB_TYPE)

## Description
Type of ADS-B hardware.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Values:** 0:Disabled, 1:uAvionix-MAVLink, 2:Sagetech, 3:uAvionix-UCP, 4:Sagetech MX Series
