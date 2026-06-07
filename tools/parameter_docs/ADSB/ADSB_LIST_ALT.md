---
layout: parameter
name: ADSB_LIST_ALT
display_name: ADSB vehicle list altitude filter
description: ADSB vehicle list altitude filter. Vehicles detected more than this altitude above our own altitude will be completely ignored. They will not show up in the SRx_ADSB stream to the GCS and will not be considered in any avoidance calculations. A value of 0 will disable this filter.
default_value: 0
range: 0 32767
units: m
group: ADSB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ADSB/AP_ADSB.cpp
---

# ADSB vehicle list altitude filter (ADSB_LIST_ALT)

## Description
Altitude filter for ADSB-detected vehicles.

## Tuning & Behavior
*   **Default Value:** 0 m
*   **Range:** 0 32767
*   **A value of 0 disables the filter.**
