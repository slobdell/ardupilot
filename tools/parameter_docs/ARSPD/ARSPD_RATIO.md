---
layout: parameter
name: ARSPD_RATIO
display_name: Airspeed ratio
description: Calibrates pitot tube pressure to velocity. Increasing this value will indicate a higher airspeed at any given dynamic pressure.
default_value: 2.0
range: 1.5 3.0
units: 
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed_Params.cpp
---

# Airspeed ratio (ARSPD_RATIO)

## Description
Scaling factor used to convert measured differential pressure into airspeed. It accounts for pitot tube design and placement.

## Tuning & Behavior
*   **Default Value:** 2.0
*   **Range:** 1.5 to 3.0
*   **Can be automatically tuned using ARSPD_AUTOCAL.**