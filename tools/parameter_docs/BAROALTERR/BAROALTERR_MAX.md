---
layout: parameter
name: BAROALTERR_MAX
display_name: Altitude error maximum
description: This is the maximum acceptable altitude discrepancy between GPS altitude and barometric pressure altitude calculated against a standard atmosphere for arming checks to pass.
default_value: 2000
range: 0 5000
units: m
group: BAROALTERR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro.cpp
---

# Altitude error maximum (BAROALTERR_MAX)

## Description
Safety check during arming that compares barometric altitude with GPS altitude.