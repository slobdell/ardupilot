---
layout: parameter
name: ADSB_LEN_WIDTH
display_name: Aircraft length and width
description: Aircraft length and width dimension options in Length and Width in meters. In most cases, use a value of 1 for smallest size.
default_value: 1
range: 
units: 
group: ADSB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ADSB/AP_ADSB.cpp
---

# Aircraft length and width (ADSB_LEN_WIDTH)

## Description
Physical dimensions of the aircraft for ADS-B reporting.

## Tuning & Behavior
*   **Default Value:** 1 (L15W23)
*   **Values:** 0:NO_DATA, 1:L15W23, 2:L25W28P5, 3:L25W34, 4:L35W33, 5:L35W38, 6:L45W39P5, 7:L45W45, 8:L55W45, 9:L55W52, 10:L65W59P5, 11:L65W67, 12:L75W72P5, 13:L75W80, 14:L85W80, 15:L85W90