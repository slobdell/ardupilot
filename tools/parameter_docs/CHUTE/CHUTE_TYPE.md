---
layout: parameter
name: CHUTE_TYPE
display_name: Parachute release mechanism type
description: Specifies whether a relay or a servo is used to trigger the parachute release.
default_value: 0
range: 
units: 
group: CHUTE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Parachute/AP_Parachute.cpp
---

# Parachute release mechanism type (CHUTE_TYPE)

## Description
Defines the hardware interface used to trigger the parachute.

## Tuning & Behavior
*   **Default Value:** 0 (Relay)
*   **Values:** 0:Relay, 10:Servo
*   **For Servo type, you must also assign a SERVOx_FUNCTION to 'ParachuteRelease'.**
