---
layout: parameter
name: Q_TAILSIT_VT_P_P
display_name: Tailsitter VT Pitch P
description: The proportional gain for pitch attitude control in tailsitter hover.
default_value: 0
range: 0 10
units: 
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter VT Pitch P (Q_TAILSIT_VT_P_P)

## Description
`Q_TAILSIT_VT_P_P` is the stiffness of the pitch axis during hover.