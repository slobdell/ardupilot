---
layout: parameter
name: AVD_W_TIME
display_name: Time Horizon Warn
description: Aircraft velocity vectors are multiplied by this time to determine closest approach. If this results in an approach closer than W_DIST_XY or W_DIST_Z then W_ACTION is undertaken.
default_value: 30
range: 1 120
units: s
group: AVD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Avoidance/AP_Avoidance.cpp
---

# Time Horizon Warn (AVD_W_TIME)

## Description
The look-ahead time for the "Warn" threat level. This provides an earlier notification than the "Fail" level.

## Tuning & Behavior
*   **Default Value:** 30 s
*   **Range:** 1 to 120 s