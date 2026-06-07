---
layout: parameter
name: TEMP1_BUS
display_name: Temperature Sensor Bus
description: Selects the I2C bus number for the temperature sensor.
default_value: 0
range: 0 3
units: 
group: TEMP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TemperatureSensor/AP_TemperatureSensor_Params.cpp#L48
---

# Temperature Sensor Bus (TEMP1_BUS)

## Description
`TEMP1_BUS` specifies which physical I2C port on the flight controller the temperature sensor is plugged into.

Most flight controllers have multiple I2C buses (e.g. internal for compass/baro, and external for GPS/Peripherals). 

*   **0:** Bus 0.
*   **1:** Bus 1 (Often the primary external port).
*   **etc.**

## Tuning & Behavior
*   **Default:** 0.
*   **Action:** If your I2C temperature sensor is not being detected, check your flight controller's hardware specification to find the correct bus number for the port you have used.