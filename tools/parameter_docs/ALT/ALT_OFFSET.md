---
layout: parameter
name: ALT_OFFSET
display_name: Altitude offset
description: Altitude offset in meters added to barometric altitude. This is used to allow for automatic adjustment of the base barometric altitude by a ground station equipped with a barometer.
default_value: 0
range: 
units: m
group: ALT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro.cpp
---

# Altitude offset (ALT_OFFSET)

## Description
A manual or GCS-provided offset added to the calculated barometric altitude. It is typically used to align the vehicle's altitude with a known ground reference.

## Tuning & Behavior
*   **Default Value:** 0 m
*   **It is automatically reset to 0 when the barometer is calibrated on reboot.**