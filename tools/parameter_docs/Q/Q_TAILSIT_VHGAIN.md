---
layout: parameter
name: Q_TAILSIT_VHGAIN
display_name: Tailsitter Vector Handling Gain
description: Gain factor for vector-based attitude control in tailsitter hover.
default_value: 0.5
range: 0 5
units: 
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter Vector Handling Gain (Q_TAILSIT_VHGAIN)

## Description
`Q_TAILSIT_VHGAIN` is the "Stiffness" of the hover control for tailsitters.

## Tuning & Behavior
*   **Default Value:** 0.5.
*   **Recommendation:** Increase if the tailsitter feels "loose" or "mushy" when trying to stay vertical.