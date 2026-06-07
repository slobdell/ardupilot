---
layout: parameter
name: Q_TAILSIT_GSCMAX
display_name: Tailsitter Max Gain Scaling
description: The maximum gain scaling factor for control surfaces in tailsitter mode.
default_value: 1.0
range: 0 5
units: 
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter Max Gain Scaling (Q_TAILSIT_GSCMAX)

## Description
`Q_TAILSIT_GSCMAX` defines the upper limit of the gain multiplier. When the plane is hovering (0 airspeed), the surfaces move at their maximum possible deflection to maintain control.