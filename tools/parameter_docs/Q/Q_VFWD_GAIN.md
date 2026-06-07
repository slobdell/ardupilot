---
layout: parameter
name: Q_VFWD_GAIN
display_name: QuadPlane Forward Motor Gain
description: The gain for using the forward motor to help maintain position in VTOL modes (active when leaning).
default_value: 0
range: 0 0.5
units: 
group: Q
visual_asset_id: vtol_vfwd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Forward Motor Gain (Q_VFWD_GAIN)

## Description
`Q_VFWD_GAIN` allows the drone to use its "Plane Propeller" to help it stay still in the wind.

Normally, a drone stays still by tilting into the wind. If the wind is very strong, the drone must tilt significantly. This parameter allows the autopilot to spin up the forward-facing motor to push against the wind, allowing the drone to stay more level while hovering.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **0.05 - 0.1** to improve hover stability in high winds.
*   **Effect:** Reduces the pitch angle required to hold position.