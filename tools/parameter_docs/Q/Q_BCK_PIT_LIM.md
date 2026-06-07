---
layout: parameter
name: Q_BCK_PIT_LIM
display_name: Back Transition Pitch Limit
description: The maximum pitch angle (in degrees) allowed during back-transition to VTOL flight.
default_value: 30
range: 0 45
units: deg
group: Q
visual_asset_id: vtol_transition_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Back Transition Pitch Limit (Q_BCK_PIT_LIM)

## Description
`Q_BCK_PIT_LIM` prevents the drone from pointing its nose too high into the air while trying to slow down.

When you transition from a "Plane" to a "Copter," the autopilot pitches up to use the wings as airbrakes. This parameter ensures the pitch isn't so extreme that the drone stalls violently or flips.

## Tuning & Behavior
*   **Default Value:** 30 degrees.
*   **Recommendation:** Leave at **30**. If your plane decelerates too slowly, you can increase this to **45**.