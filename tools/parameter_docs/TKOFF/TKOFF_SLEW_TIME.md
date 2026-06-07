---
layout: parameter
name: TKOFF_SLEW_TIME
display_name: Takeoff Slew Time
description: The time (in seconds) to ramp the throttle from hover to the takeoff climb throttle in autonomous modes.
default_value: 2.0
range: 0 10
units: s
group: TKOFF
visual_asset_id: takeoff_sequence_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/takeoff.cpp#L100
---

# Takeoff Slew Time (TKOFF_SLEW_TIME)

## Description
`TKOFF_SLEW_TIME` makes automatic takeoffs smoother.

When you switch to **Auto** or **Guided** and command a takeoff, the drone doesn't just jump to full climb speed instantly. Instead, it smoothly ramps up the throttle target over this duration. This prevents the drone from "launching like a rocket" and stressing the battery or motors.

*   **Low Value (0.5s):** Aggressive takeoff.
*   **High Value (5.0s):** Very gentle lift-off.

## Tuning & Behavior
*   **Default Value:** 2.0 seconds.
*   **Cinematography:** Increase to **4.0s** for a buttery smooth start to the shot.