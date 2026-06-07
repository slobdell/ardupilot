---
layout: parameter
name: FIELD_ELV
display_name: field elevation
description: User provided field elevation in meters. This is used to improve the calculation of the altitude the vehicle is at.
default_value: 0
range: 
units: m
group: FIELD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro.cpp
---

# field elevation (FIELD_ELV)

## Description
Manual input for the airfield's elevation above sea level. This improves absolute altitude accuracy.