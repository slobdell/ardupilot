---
layout: parameter
name: EK2_ALT_SOURCE
display_name: Primary altitude sensor source
description: Primary height sensor used by the EKF2.
default_value: 0
range: 0 3
units: 
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Primary altitude sensor source (EK2_ALT_SOURCE)

## Description
Selects the primary hardware source for altitude estimation within the EKF2 algorithm.

## Tuning & Behavior
*   **Default Value:** 0 (Baro)
*   **Values:** 0:Use Baro, 1:Use Range Finder, 2:Use GPS, 3:Use Range Beacon
