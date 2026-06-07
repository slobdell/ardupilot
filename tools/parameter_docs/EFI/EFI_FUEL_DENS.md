---
layout: parameter
name: EFI_FUEL_DENS
display_name: ECU Fuel Density
description: Used to calculate fuel consumption (kg/m^3).
default_value: 0
range: 0 10000
units: kg/m^3
group: EFI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_EFI/AP_EFI.cpp
---

# ECU Fuel Density (EFI_FUEL_DENS)

## Description
The density of the fuel being used, required for accurate mass-based fuel consumption calculations.
