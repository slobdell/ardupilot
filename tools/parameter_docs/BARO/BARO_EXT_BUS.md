---
layout: parameter
name: BARO_EXT_BUS
display_name: External Barometer I2C Bus
description: Selects the I2C bus number used for an optional external barometer.
default_value: -1
range: -1 6
units: 
group: BARO
visual_asset_id: i2c_bus_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Baro/AP_Baro.cpp#L112
---

# External Barometer I2C Bus (BARO_EXT_BUS)

## Description
`BARO_EXT_BUS` is used if you are connecting an external high-precision barometer to your flight controller via an I2C cable.

*   **-1 (Disabled/Auto):** The flight controller will probe all external buses automatically.
*   **0-6:** Forces the flight controller to look on a specific I2C bus for the sensor.

## The Engineer's View
Used in `AP_Baro::init()`. 
Manually setting the bus can speed up the boot process and prevent conflicts if multiple devices on different buses have the same I2C address.

## Tuning & Behavior
*   **Default Value:** -1
*   **Recommendation:** Leave at **-1** unless you have a specific hardware conflict or are using an unusual board configuration.