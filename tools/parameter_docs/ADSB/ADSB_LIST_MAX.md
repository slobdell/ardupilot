---
layout: parameter
name: ADSB_LIST_MAX
display_name: ADSB vehicle list size
description: ADSB list size of nearest vehicles. Longer lists take longer to refresh with lower SRx_ADSB values.
default_value: 25
range: 1 100
units: 
group: ADSB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ADSB/AP_ADSB.cpp
---

# ADSB vehicle list size (ADSB_LIST_MAX)

## Description
Maximum number of vehicles to track in the ADSB list.

## Tuning & Behavior
*   **Default Value:** 25
*   **Range:** 1 100