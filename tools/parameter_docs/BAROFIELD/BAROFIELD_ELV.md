---
layout: parameter
name: BAROFIELD_ELV
display_name: field elevation
description: User provided field elevation in meters. This is used to improve the calculation of the altitude the vehicle is at.
default_value: 0
range: 
units: m
group: BAROFIELD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro.cpp
---

# field elevation (BAROFIELD_ELV)

## Description
Manual input for the airfield's elevation above sea level. This improves the absolute altitude accuracy by providing a known ground reference.

## Tuning & Behavior
*   **Default Value:** 0 m
*   **This parameter is not persistent and will be reset to 0 every time the vehicle is rebooted.**