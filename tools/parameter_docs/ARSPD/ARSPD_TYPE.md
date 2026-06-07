---
layout: parameter
name: ARSPD_TYPE
display_name: Airspeed type
description: Type of airspeed sensor.
default_value: 0
range: 
units: 
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed_Params.cpp
---

# Airspeed type (ARSPD_TYPE)

## Description
Enables and selects the hardware type for the primary airspeed sensor.

## Tuning & Behavior
*   **Default Value:** 0 (None)
*   **Common Values:** 1:I2C-MS4525D0, 2:Analog, 3:I2C-MS5525, 6:I2C-SDP3X, 8:DroneCAN, 100:SITL
*   **Requires reboot to initialize the driver.**