---
layout: parameter
name: ARSPD_USE
display_name: Airspeed use
description: Enables airspeed use for automatic throttle modes. Continues to display and log airspeed if set to 0. Uses airspeed for control if set to 1. Only uses airspeed when throttle = 0 if set to 2 (useful for gliders with airspeed sensors behind propellers).
default_value: 0
range: 0 2
units: 
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed_Params.cpp
---

# Airspeed use (ARSPD_USE)

## Description
Determines if the measured airspeed is used by the flight controller for autonomous speed and altitude management (TECS).

## Tuning & Behavior
*   **Default Value:** 0 (DoNotUse - Logging only)
*   **Values:** 0:DoNotUse, 1:Use, 2:UseWhenZeroThrottle
*   **Set to 1 only after verifying the sensor is healthy and properly calibrated.**