---
layout: parameter
name: AVD_F_TIME
display_name: Time Horizon Fail
description: Aircraft velocity vectors are multiplied by this time to determine closest approach. If this results in an approach closer than F_DIST_XY or F_DIST_Z then F_ACTION is undertaken.
default_value: 30
range: 1 120
units: s
group: AVD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Avoidance/AP_Avoidance.cpp
---

# Time Horizon Fail (AVD_F_TIME)

## Description
The look-ahead time for the "Fail" threat level. If a collision is predicted to occur within this many seconds, the AVD_F_ACTION will be triggered.

## Tuning & Behavior
*   **Default Value:** 30 s
*   **A larger value provides more time to react but may lead to more false alarms.**
