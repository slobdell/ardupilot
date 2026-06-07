---
layout: parameter
name: Q_TAILSIT_RLL_MX
display_name: Tailsitter Max Roll Rate
description: The maximum roll rate (in degrees per second) allowed in tailsitter hover.
default_value: 0
range: 0 180
units: deg/s
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter Max Roll Rate (Q_TAILSIT_RLL_MX)

## Description
`Q_TAILSIT_RLL_MX` sets the "Sensitivity" of the yaw axis (which becomes body-roll in hover) for tailsitters.