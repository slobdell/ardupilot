---
layout: parameter
name: FLOW_ADDR
display_name: Address on the bus
description: This is used to select between multiple possible I2C addresses for some sensor types. For PX4Flow you can choose 0 to 7 for the 8 possible addresses on the I2C bus.
default_value: 0
range: 0 127
units: 
group: FLOW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OpticalFlow/AP_OpticalFlow.cpp
---

# Address on the bus (FLOW_ADDR)

## Description
I2C address selection for the optical flow sensor.

## Tuning & Behavior
*   **Default Value:** 0
*   **Range:** 0 127