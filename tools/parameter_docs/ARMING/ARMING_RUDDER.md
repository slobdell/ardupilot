---
layout: parameter
name: ARMING_RUDDER
display_name: Arming with Rudder enable/disable
description: Allow arm/disarm by rudder input. When enabled arming can be done with right rudder, disarming with left rudder.
default_value: 1
range: 0 2
units: 
group: ARMING
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Arming/AP_Arming.cpp
---

# Arming with Rudder enable/disable (ARMING_RUDDER)

## Description
Enables or disables the ability to arm and disarm the vehicle using the rudder stick on the RC transmitter.

## Tuning & Behavior
*   **Default Value:** 1 (Arming Only for Plane, Arm/Disarm for Copter)
*   **Values:** 0:Disabled, 1:ArmingOnly, 2:ArmOrDisarm
*   **Rudder arming only works when the throttle is at its minimum position.**
