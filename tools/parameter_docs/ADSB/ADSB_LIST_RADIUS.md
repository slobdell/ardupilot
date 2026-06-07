---
layout: parameter
name: ADSB_LIST_RADIUS
display_name: ADSB vehicle list radius filter
description: ADSB vehicle list radius filter. Vehicles detected outside this radius will be completely ignored. They will not show up in the SRx_ADSB stream to the GCS and will not be considered in any avoidance calculations. A value of 0 will disable this filter.
default_value: 2000
range: 0 100000
units: m
group: ADSB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ADSB/AP_ADSB.cpp
---

# ADSB vehicle list radius filter (ADSB_LIST_RADIUS)

## Description
Distance filter for ADSB-detected vehicles.

## Tuning & Behavior
*   **Default Value:** 2000 m (Copter/Rover), 10000 m (Plane)
*   **Range:** 0 100000
*   **A value of 0 disables the filter.**