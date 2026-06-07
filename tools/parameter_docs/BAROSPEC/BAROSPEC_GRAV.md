---
layout: parameter
name: BAROSPEC_GRAV
display_name: Specific Gravity
description: This sets the specific gravity of the fluid when flying an underwater ROV.
default_value: 1.0
range: 
units: 
group: BAROSPEC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro.cpp
---

# Specific Gravity (BAROSPEC_GRAV)

## Description
Defines the density of the surrounding fluid for ArduSub vehicles. This is used to convert pressure readings into accurate depth measurements.

## Tuning & Behavior
*   **Default Value:** 1.0 (Freshwater)
*   **Common Values:** 1.0:Freshwater, 1.024:Saltwater