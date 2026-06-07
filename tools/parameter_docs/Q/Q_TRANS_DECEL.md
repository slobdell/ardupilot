---
layout: parameter
name: Q_TRANS_DECEL
display_name: QuadPlane Transition Deceleration
description: The deceleration rate (in m/s/s) used when transitioning from forward flight to hover.
default_value: 2.0
range: 0.5 5.0
units: m/s/s
group: Q
visual_asset_id: vtol_transition_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Transition Deceleration (Q_TRANS_DECEL)

## Description
`Q_TRANS_DECEL` determines how hard the drone "Brakes" when stopping.

When you switch from FBWA to QHOVER, the plane pitches up to slow down. This parameter sets how aggressively it pitches up.

## Tuning & Behavior
*   **Default Value:** 2.0 m/s/s.
*   **Higher Value:** Faster stop, but the nose will pitch up sharply (Cobra maneuver).
*   **Lower Value:** Smoother, gradual stop, but takes more distance.