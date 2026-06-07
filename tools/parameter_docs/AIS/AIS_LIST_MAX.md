---
layout: parameter
name: AIS_LIST_MAX
display_name: AIS vessel list size
description: AIS list size of nearest vessels. Longer lists take longer to refresh with lower SRx_ADSB values.
default_value: 25
range: 1 100
units: 
group: AIS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AIS/AP_AIS.cpp
---

# AIS vessel list size (AIS_LIST_MAX)

## Description
Maximum number of vessels to track in the AIS list.

## Tuning & Behavior
*   **Default Value:** 25
*   **Range:** 1 to 100