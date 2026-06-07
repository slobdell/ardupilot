---
layout: parameter
name: Q_TAILSIT_VT_R_P
display_name: Tailsitter VT Roll P
description: The proportional gain for roll attitude control in tailsitter hover.
default_value: 0
range: 0 10
units: 
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter VT Roll P (Q_TAILSIT_VT_R_P)

## Description
`Q_TAILSIT_VT_R_P` is the "Stiffness" of the roll axis during hover.

*   **0 (Default):** Use standard multicopter gains (`Q_A_RAT_RLL_P`).
*   **Non-Zero:** Overrides the standard gains with this specific value for hover only.