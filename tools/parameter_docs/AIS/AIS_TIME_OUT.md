---
layout: parameter
name: AIS_TIME_OUT
display_name: AIS vessel time out
description: If no updates are received in this time a vessel will be removed from the list.
default_value: 600
range: 1 2000
units: s
group: AIS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AIS/AP_AIS.cpp
---

# AIS vessel time out (AIS_TIME_OUT)

## Description
Duration after which a vessel is removed from the tracking list if no updates are received.

## Tuning & Behavior
*   **Default Value:** 600 s (10 minutes)
*   **Range:** 1 to 2000 s