---
layout: parameter
name: TECS_RLL2THR
display_name: Roll to Throttle Compensation
description: Automatically increases throttle during turns to compensate for the extra drag and loss of vertical lift.
default_value: 10
range: 0 50
units: 
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L109
---

# Roll to Throttle Compensation (TECS_RLL2THR)

## Description
`TECS_RLL2THR` is the "Turn Gas."

When a plane banks into a turn, it naturally slows down and loses lift. This parameter automatically "Pushes the Gas" when the wings are tilted, ensuring the plane maintains its airspeed and altitude through the maneuver.

## Tuning & Behavior
*   **Default Value:** 10.
*   **Recommendation:** If the plane loses too much speed in sharp turns, increase this value. If it speeds up excessively while turning, decrease it.
*   **Physics:** This is a feed-forward term based on the bank angle.
    $$ \text{Throttle}_{extra} = k \cdot (1 - \cos(\text{roll})) $$