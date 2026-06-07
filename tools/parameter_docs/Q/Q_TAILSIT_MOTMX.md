---
layout: parameter
name: Q_TAILSIT_MOTMX
display_name: Tailsitter Motor Max Output
description: Maximum motor output allowed for attitude control in tailsitter hover.
default_value: 0
range: 0 1
units: 
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter Motor Max Output (Q_TAILSIT_MOTMX)

## Description
`Q_TAILSIT_MOTMX` caps how much work the motors do to keep the plane level, ensuring there is enough power left to keep the plane in the air.