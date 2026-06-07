---
layout: parameter
name: ARSPD_PRIMARY
display_name: Primary airspeed sensor
description: This selects which airspeed sensor will be the primary if multiple sensors are found.
default_value: 0
range: 0 1
units: 
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed.cpp
---

# Primary airspeed sensor (ARSPD_PRIMARY)

## Description
Selects the primary sensor for flight control in dual-airspeed configurations.

## Tuning & Behavior
*   **Default Value:** 0 (First Sensor)
*   **Values:** 0:FirstSensor, 1:2ndSensor