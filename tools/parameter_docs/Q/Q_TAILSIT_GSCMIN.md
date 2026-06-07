---
layout: parameter
name: Q_TAILSIT_GSCMIN
display_name: Tailsitter Min Gain Scaling
description: The minimum gain scaling factor for control surfaces in tailsitter mode.
default_value: 0.4
range: 0 1
units: 
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter Min Gain Scaling (Q_TAILSIT_GSCMIN)

## Description
`Q_TAILSIT_GSCMIN` is the "Floor" for the gain multiplier. When the plane is flying fast, we reduce the surface movement (gain) to prevent vibration. This parameter ensures we don't reduce it so much that the drone becomes unresponsive.