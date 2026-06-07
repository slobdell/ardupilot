---
layout: parameter
name: ADSB_OFFSET_LAT
display_name: GPS antenna lateral offset
description: GPS antenna lateral offset. This describes the physical location offset from center of the GPS antenna on the aircraft.
default_value: 4
range: 
units: 
group: ADSB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ADSB/AP_ADSB.cpp
---

# GPS antenna lateral offset (ADSB_OFFSET_LAT)

## Description
Physical location offset from the center of the GPS antenna on the aircraft.

## Tuning & Behavior
*   **Default Value:** 4 (Center)
*   **Values:** 0:NoData, 1:Left2m, 2:Left4m, 3:Left6m, 4:Center, 5:Right2m, 6:Right4m, 7:Right6m