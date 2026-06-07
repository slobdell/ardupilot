---
layout: parameter
name: Q_TRAN_PIT_MAX
display_name: QuadPlane Transition Pitch Max
description: The maximum pitch angle (in degrees) allowed during transition to forward flight.
default_value: 3
range: 0 30
units: deg
group: Q
visual_asset_id: vtol_transition_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Transition Pitch Max (Q_TRAN_PIT_MAX)

## Description
`Q_TRAN_PIT_MAX` keeps the nose down during acceleration.

When the pusher motor starts, the plane naturally wants to pitch up. This parameter clamps the pitch angle to ensure the plane stays level and accelerates efficiently.

## Tuning & Behavior
*   **Default Value:** 3 degrees.
*   **Recommendation:** Increase to **10-15** for faster acceleration if your airframe has plenty of power.