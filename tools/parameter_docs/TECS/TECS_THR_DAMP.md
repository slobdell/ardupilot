---
layout: parameter
name: TECS_THR_DAMP
display_name: Throttle Damping
description: The damping gain for the throttle control loop in TECS.
default_value: 0.5
range: 0.1 1.0
units: 
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L104
---

# Throttle Damping (TECS_THR_DAMP)

## Description
`TECS_THR_DAMP` prevents the motor from "Pulsing" or hunting for the correct speed.

It smooths out the throttle commands sent to the ESC. If you hear your motor constantly changing pitch (speeding up and slowing down) while in a steady cruise, your damping might be too low.

## Tuning & Behavior
*   **Default Value:** 0.5.
*   **Recommendation:** If the motor "Surges," increase this value by 0.1.
