---
layout: parameter
name: ARSPD_PSI_RANGE
display_name: PSI range of the device
description: This parameter allows you to set the PSI (pounds per square inch) range for your sensor.
default_value: 1.0
range: 
units: PSI
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed_Params.cpp
---

# PSI range of the device (ARSPD_PSI_RANGE)

## Description
The pressure range of the airspeed sensor hardware.

## Tuning & Behavior
*   **Default Value:** 1.0 PSI
*   **Do not change this unless required by the specific sensor datasheet (e.g., DLVR sensors).**
