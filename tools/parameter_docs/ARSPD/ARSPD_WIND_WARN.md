---
layout: parameter
name: ARSPD_WIND_WARN
display_name: Airspeed and GPS speed difference warning
description: If the difference between airspeed and GPS speed is greater than this value the sensor will issue a warning.
default_value: 0
range: 0 127
units: m/s
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed.cpp
---

# Airspeed and GPS speed difference warning (ARSPD_WIND_WARN)

## Description
Threshold for issuing a non-fatal warning about suspected airspeed sensor inaccuracies compared to GPS groundspeed.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Range:** 0 to 127 m/s