---
layout: parameter
name: Q_FWD_THR_USE
display_name: QuadPlane Forward Throttle Use
description: Controls how the forward motor is used in VTOL modes (QHOVER, QLOITER, QLAND).
default_value: 0
range: 0 3
units: 
group: Q
visual_asset_id: vtol_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Forward Throttle Use (Q_FWD_THR_USE)

## Description
`Q_FWD_THR_USE` allows the forward pusher motor to help the drone hold position against strong winds while in a hover mode.

*   **0 (Disabled):** The forward motor is off in VTOL modes.
*   **1 (Position Hold):** The forward motor is used to fight headwind in QLOITER/QLAND.
*   **2 (Distance):** Used for position hold and to speed up travel to waypoints in VTOL modes.

## The Engineer's View
If enabled, the position controller calculates a pitch demand. If the pitch demand is "nose down" (fight wind or move forward), the mixer allocates some of that demand to the forward motor instead of just pitching the quadcopter rotors. This keeps the fuselage level and efficient.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **1** if you fly in windy conditions. It significantly improves position holding capability.