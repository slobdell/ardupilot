---
layout: parameter
name: ARSPD_PIN
display_name: Airspeed pin
description: The pin number that the airspeed sensor is connected to for analog sensors.
default_value: 0
range: 
units: 
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed_Params.cpp
---

# Airspeed pin (ARSPD_PIN)

## Description
Specifies the analog input pin used for analog airspeed sensors.

## Tuning & Behavior
*   **Default Value:** 0
*   **Common Values:** 2:Pixhawk/Pixracer, 13:Pixhawk2_PM2, 14:CubeOrange
*   **Only relevant if ARSPD_TYPE is set to 2 (Analog).**