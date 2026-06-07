---
layout: parameter
name: BAROEXT_BUS
display_name: External baro bus
description: This selects the bus number for looking for an I2C barometer. When set to -1 it will probe all external i2c buses based on the BARO_PROBE_EXT parameter.
default_value: -1
range: 
units: 
group: BAROEXT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro.cpp
---

# External baro bus (BAROEXT_BUS)

## Description
Specifies a particular I2C bus to search for an external barometer.

## Tuning & Behavior
*   **Default Value:** -1 (Probe all buses)
*   **Values:** -1:Disabled/Auto, 0:Bus0, 1:Bus1, 6:Bus6