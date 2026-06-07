---
layout: parameter
name: ADSB_ICAO_SPECL
display_name: ICAO_ID of special vehicle
description: ICAO_ID of special vehicle that ignores ADSB_LIST_RADIUS and ADSB_LIST_ALT. The vehicle is always tracked. Use 0 to disable.
default_value: 0
range: 
units: 
group: ADSB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ADSB/AP_ADSB.cpp
---

# ICAO_ID of special vehicle (ADSB_ICAO_SPECL)

## Description
Enables tracking of a specific vehicle by its ICAO ID, bypassing distance and altitude filters.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)