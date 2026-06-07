---
layout: parameter
name: KFF_THR2PTCH
display_name: Throttle to Pitch Mix
description: Automatically adds a pitch correction (in degrees) proportional to the current throttle level.
default_value: 0
range: -5 5
units: deg
group: KFF
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L80
---

# Throttle to Pitch Mix (KFF_THR2PTCH)

## Description
`KFF_THR2PTCH` compensates for the physical design of an aircraft where the motor's thrust "pushes" the nose up or down.

Many planes, especially those with high or low mounted motors, tend to pitch up when you add power. To fly level, you have to manually push the elevator down. This parameter automates that correction. If you set it to **2.0**, then at 100% throttle, the autopilot will automatically command a 2-degree pitch-down correction.

## Tuning & Behavior
*   **Positive Values:** Pitch the nose **UP** as throttle increases.
*   **Negative Values:** Pitch the nose **DOWN** as throttle increases.
*   **Calibration:** Fly the plane in MANUAL mode. Add power and see which way the nose moves. Adjust this parameter until the plane maintains a level attitude when changing throttle.