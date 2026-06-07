---
layout: parameter
name: Q_TAILSIT_VFGAIN
display_name: Tailsitter Vector Forward Gain
description: Gain factor for forward thrust vectoring in tailsitter mode.
default_value: 0
range: 0 5
units: 
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter Vector Forward Gain (Q_TAILSIT_VFGAIN)

## Description
`Q_TAILSIT_VFGAIN` defines how much "Forward Push" the VTOL motors provide while the plane is still mostly vertical.