---
layout: parameter
name: TURN_MAX_G
display_name: Turning maximum G force
description: The maximum turning acceleration (in units of gravities) that the rover can handle while remaining stable.
default_value: 0.6
range: 0.1 10
units: G
group: TURN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.cpp#L549
---

# TURN_MAX_G: Turning maximum G force

## Description
The maximum turning acceleration (in units of gravities) that the rover can handle while remaining stable.

## Values
- **Range:** 0.1 to 10
- **Units:** G (Gravities)
- **Default:** 0.6

## Description
This parameter is a safety limit for **Rover**.

- **Function:** It tells the navigation controller the maximum lateral acceleration (cornering force) the vehicle can sustain without flipping over or skidding.
- **Effect:** If a waypoint requires a turn that would exceed this G-force at current speed, the rover will automatically slow down *before* entering the turn to keep the G-force below this limit.
- **Tuning:** 
    - **Low CG / Wide vehicles:** Can handle higher values (e.g., 1.0G or more).
    - **High CG / Narrow vehicles:** Must be set lower (e.g., 0.3G) to prevent rollovers.

