---
layout: parameter
name: AVD_F_RCVRY
display_name: Recovery behaviour after a fail event
description: Determines what the aircraft will do after a fail event is resolved.
default_value: 2
range: 0 3
units: 
group: AVD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Avoidance/AP_Avoidance.cpp
---

# Recovery behaviour after a fail event (AVD_F_RCVRY)

## Description
Specifies the flight mode or action the aircraft transitions to once a previously detected collision threat has been cleared.

## Tuning & Behavior
*   **Default Value:** 2 (RTL) for Copter, 3 (Resume/Loiter) for Plane
*   **Values:** 0:Remain in AVOID_ADSB, 1:Resume previous flight mode, 2:RTL, 3:Resume if AUTO else Loiter
