---
layout: parameter
name: ARSPD_OFFSET
display_name: Airspeed offset
description: Airspeed calibration offset. Represents the pressure reported by the sensor at zero airspeed.
default_value: 0
range: 
units: 
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed_Params.cpp
---

# Airspeed offset (ARSPD_OFFSET)

## Description
Stored calibration value for the pressure sensor's zero-point.

## Tuning & Behavior
*   **Default Value:** 0
*   **Usually set automatically during the "Preflight Calibration" process with the pitot tube covered.**