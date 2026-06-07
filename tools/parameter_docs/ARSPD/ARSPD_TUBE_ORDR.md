---
layout: parameter
name: ARSPD_TUBE_ORDR
display_name: Control pitot tube order
description: Controls whether the order in which the tubes are attached to your pitot tube matters.
default_value: 2
range: 0 2
units: 
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed_Params.cpp
---

# Control pitot tube order (ARSPD_TUBE_ORDR)

## Description
Defines which pressure port (stagnation vs static) is connected to which sensor input.

## Tuning & Behavior
*   **Default Value:** 2 (Auto Detect)
*   **Values:** 0:Normal, 1:Swapped, 2:Auto Detect
*   **Set to 0 or 1 if the sensor consistently reports negative airspeed on the ground.**