---
layout: parameter
name: BAROGND_TEMP
display_name: ground temperature
description: User provided ambient ground temperature in degrees Celsius. This is used to improve the calculation of the altitude the vehicle is at.
default_value: 0
range: 
units: degC
group: BAROGND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro.cpp
---

# ground temperature (BAROGND_TEMP)

## Description
Manual input for the ambient temperature at the ground level. ArduPilot uses this to improve the barometric altitude calculation, which is temperature-dependent.

## Tuning & Behavior
*   **Default Value:** 0 degC (Use internal sensor measurement)
*   **This parameter is not persistent and will be reset to 0 every time the vehicle is rebooted.**