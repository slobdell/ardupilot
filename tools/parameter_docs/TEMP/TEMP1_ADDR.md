---
layout: parameter
name: TEMP1_ADDR
display_name: Temperature Sensor Address (Sensor 1)
description: The I2C address of the temperature sensor.
default_value: 0
range: 0 127
units: 
group: TEMP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TemperatureSensor/AP_TemperatureSensor_Params.cpp#L56
---

# Temperature Sensor Address (TEMP1_ADDR)

## Description
`TEMP1_ADDR` sets the 7-bit I2C address for digital temperature sensors (Types 1-4, 7). 

Most sensors have a fixed or jumper-selectable address. If you have multiple sensors of the same type on the same bus, you must configure them with unique addresses and set those addresses here.

## Tuning & Behavior
*   **Default:** 0 (Use the driver's default address for the selected type).
*   **Recommendation:** Only change this if your hardware documentation specifies a non-standard I2C address.