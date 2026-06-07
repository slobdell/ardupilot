---
layout: parameter
name: AHRS_WIND_MAX
display_name: Maximum wind
description: This sets the maximum allowable difference between ground speed and airspeed. A value of zero means to use the airspeed as is. This allows the plane to cope with a failing airspeed sensor by clipping it to groundspeed plus/minus this limit.
default_value: 0.0
range: 0 127
units: m/s
group: AHRS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AHRS/AP_AHRS.cpp
---

# Maximum wind (AHRS_WIND_MAX)

## Description
Safety limit for the discrepancy between groundspeed and airspeed, providing redundancy against airspeed sensor failure.

## Tuning & Behavior
*   **Default Value:** 0.0 m/s (Disabled)
*   **Range:** 0 to 127 m/s