---
layout: parameter
name: Q_TAILSIT_VT_Y_P
display_name: Tailsitter VT Yaw P
description: The proportional gain for yaw attitude control in tailsitter hover.
default_value: 0
range: 0 10
units: 
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter VT Yaw P (Q_TAILSIT_VT_Y_P)

## Description
`Q_TAILSIT_VT_Y_P` is the stiffness of the yaw axis during hover.