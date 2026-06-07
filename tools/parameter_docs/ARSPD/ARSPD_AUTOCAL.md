---
layout: parameter
name: ARSPD_AUTOCAL
display_name: Automatic airspeed ratio calibration
description: Enables automatic adjustment of airspeed ratio during a calibration flight based on estimation of ground speed and true airspeed.
default_value: 0
range: 0 1
units: 
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed_Params.cpp
---

# Automatic airspeed ratio calibration (ARSPD_AUTOCAL)

## Description
A feature that dynamically tunes the ARSPD_RATIO during flight by comparing groundspeed and estimated wind to measured airspeed.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Should be disabled once the ratio has converged to a stable value.**