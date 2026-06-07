---
layout: parameter
name: ALTERR_MAX
display_name: Altitude error maximum
description: This is the maximum acceptable altitude discrepancy between GPS altitude and barometric pressure altitude calculated against a standard atmosphere for arming checks to pass. If you are getting an arming error due to this parameter then you may have a faulty or substituted barometer. This check is disabled if the value is zero.
default_value: 2000
range: 0 5000
units: m
group: ALTERR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro.cpp
---

# Altitude error maximum (ALTERR_MAX)

## Description
Safety check during arming that compares barometric altitude with GPS altitude. If the discrepancy exceeds this value, arming will be blocked.

## Tuning & Behavior
*   **Default Value:** 2000 m
*   **Range:** 0 to 5000 m
*   **A value of 0 disables this arming check.**
*   **Commonly used to detect hardware mismatches (e.g., MS5607 vs MS5611).**