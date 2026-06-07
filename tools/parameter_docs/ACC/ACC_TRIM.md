---
layout: parameter
name: ACC_TRIM
display_name: Accelerometer Trim (SITL)
description: Offset for the simulated accelerometer in SITL.
default_value: 0
range: 
units: 
group: ACC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SITL.cpp
---

# Accelerometer Trim (ACC_TRIM)

## Description
Simulated accelerometer trim used in the SITL environment to test trim estimation logic.

## Tuning & Behavior
*   **Default Value:** 0