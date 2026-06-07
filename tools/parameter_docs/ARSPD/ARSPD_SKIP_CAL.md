---
layout: parameter
name: ARSPD_SKIP_CAL
display_name: Skip airspeed offset calibration on startup
description: Allows skipping the airspeed offset calibration on startup, instead using the offset from the last calibration.
default_value: 0
range: 0 1
units: 
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed_Params.cpp
---

# Skip airspeed offset calibration on startup (ARSPD_SKIP_CAL)

## Description
Saves time during boot by skipping the zero-airspeed pressure calibration.

## Tuning & Behavior
*   **Default Value:** 0 (Always calibrate)
*   **Only recommended if your sensor has very low drift and you cannot easily cover the pitot tube during boot.**
*   **Requires a prior successful manual calibration.**
