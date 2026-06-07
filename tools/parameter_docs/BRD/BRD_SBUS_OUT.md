---
layout: parameter
name: BRD_SBUS_OUT
display_name: SBUS output rate
description: Sets the SBUS output frame rate in Hz.
default_value: 0
range: 0 7
units: Hz
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# SBUS output rate (BRD_SBUS_OUT)

## Description
Configures the refresh rate of the SBUS output port.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Values:** 1:50Hz, 2:75Hz, 3:100Hz, 4:150Hz, 5:200Hz, 6:250Hz, 7:300Hz