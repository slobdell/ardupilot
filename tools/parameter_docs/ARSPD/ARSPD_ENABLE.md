---
layout: parameter
name: ARSPD_ENABLE
display_name: Airspeed Enable
description: Enable airspeed sensor support.
default_value: 0
range: 0 1
units: 
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed.cpp
---

# Airspeed Enable (ARSPD_ENABLE)

## Description
Global master switch to enable the airspeed sensor library.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Values:** 0:Disable, 1:Enable
*   **Requires reboot to take effect.**