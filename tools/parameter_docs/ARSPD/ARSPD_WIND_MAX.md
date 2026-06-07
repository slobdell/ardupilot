---
layout: parameter
name: ARSPD_WIND_MAX
display_name: Maximum airspeed and ground speed difference
description: If the difference between airspeed and ground speed is greater than this value the sensor will be marked unhealthy.
default_value: 0
range: 0 127
units: m/s
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed.cpp
---

# Maximum airspeed and ground speed difference (ARSPD_WIND_MAX)

## Description
Sanity check threshold comparing reported airspeed to groundspeed. If the difference is physically impossible (given known wind limits), the sensor is flagged as failed.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Range:** 0 to 127 m/s
*   **Works in conjunction with ARSPD_OPTIONS bit 0.**