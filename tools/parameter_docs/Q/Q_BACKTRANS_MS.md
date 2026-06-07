---
layout: parameter
name: Q_BACKTRANS_MS
display_name: QuadPlane Back Transition Time
description: The duration (in milliseconds) of the transition from fixed-wing to VTOL flight.
default_value: 3000
range: 0 10000
units: ms
group: Q
visual_asset_id: vtol_transition_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Back Transition Time (Q_BACKTRANS_MS)

## Description
`Q_BACKTRANS_MS` sets how long the drone spends decelerating and mixing controls when switching from Plane mode to Copter mode (e.g., when you switch to QHOVER while flying fast).

A smoother transition gives the VTOL motors time to spin up before the wing loses lift.

## Tuning & Behavior
*   **Default Value:** 3000 ms (3 seconds).
*   **Recommendation:** Set to **3000-5000** for smooth stops.