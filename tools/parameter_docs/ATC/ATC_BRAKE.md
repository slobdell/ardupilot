---
layout: parameter
name: ATC_BRAKE
display_name: Speed Control Brake Enable
description: Enables the use of reverse throttle to slow down the vehicle.
default_value: 1
range: 0 1
units: 
group: ATC
visual_asset_id: brake_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.cpp#L265
---

# Speed Control Brake Enable (ATC_BRAKE)

## Description
`ATC_BRAKE` allows the autopilot to put the car in "Reverse" to slow down.

*   **0: Disabled.** The rover will coast to a stop (drag only).
*   **1: Enabled.** The rover actively reverses the motor to brake.

## Tuning & Behavior
*   **Default Value:** 1.
*   **Boats:** Be careful. Reversing the prop quickly can cause cavitation or unscrew the prop nut.