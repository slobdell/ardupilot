---
layout: parameter
name: ARSPD_BUS
display_name: Airspeed I2C bus
description: Bus number of the I2C bus where the airspeed sensor is connected.
default_value: 1
range: 0 3
units: 
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed_Params.cpp
---

# Airspeed I2C bus (ARSPD_BUS)

## Description
Selects the I2C physical bus on which the digital airspeed sensor is located.

## Tuning & Behavior
*   **Default Value:** 1
*   **May not match the labels on the flight controller board.**