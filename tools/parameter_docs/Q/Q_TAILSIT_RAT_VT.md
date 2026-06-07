---
layout: parameter
name: Q_TAILSIT_RAT_VT
display_name: Tailsitter Transition Rate
description: The maximum pitch rate (in degrees per second) used during tailsitter transition.
default_value: 0
range: 0 100
units: deg/s
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter Transition Rate (Q_TAILSIT_RAT_VT)

## Description
`Q_TAILSIT_RAT_VT` controls how "Fast" the plane tips over during a transition.

*   **Low Value (e.g., 20):** Very slow, graceful tip-over. Safe but uses more battery.
*   **High Value (e.g., 60):** Aggressive, fast transition. More efficient.

## Tuning & Behavior
*   **Default Value:** 0 (Uses `Q_TRANSITION_MS` calculation).