---
layout: parameter
name: Q_TAILSIT_THR_VT
display_name: Tailsitter Transition Throttle
description: The throttle threshold for initiating a transition in tailsitter mode.
default_value: 0
range: 0 100
units: '%'
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter Transition Throttle (Q_TAILSIT_THR_VT)

## Description
`Q_TAILSIT_THR_VT` prevents the plane from trying to fly forward if the motors aren't spinning fast enough to provide lift. 

## Tuning & Behavior
*   **Default Value:** 0.