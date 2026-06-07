---
layout: parameter
name: RNGFND1_ADDR
display_name: Rangefinder Address (Sensor 1)
description: The I2C address or DroneCAN Node ID of the sensor.
default_value: 0
range: 0 127
units: 
group: RNGFND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L107
---

# Rangefinder Address (RNGFND1_ADDR)

## Description
`RNGFND1_ADDR` sets the unique identifier used to communicate with the sensor over a digital bus.

*   **For I2C sensors:** This is the 7-bit I2C address (e.g., 0x62 for LIDAR-Lite).
*   **For DroneCAN sensors:** This is the Node ID assigned to the sensor.
*   **For Serial/Analog sensors:** This parameter is generally ignored.

## Tuning & Behavior
*   **Default:** 0 (Use the driver's default address).
*   **Setup:** Only change this if you have multiple identical sensors on the same bus and have reconfigured one to a non-default address.