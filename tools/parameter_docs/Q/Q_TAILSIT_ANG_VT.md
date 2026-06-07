---
layout: parameter
name: Q_TAILSIT_ANG_VT
display_name: Tailsitter VT Angle
description: The target pitch angle (in degrees) during the VTOL phase of a tailsitter transition.
default_value: 0
range: -30 30
units: deg
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter VT Angle (Q_TAILSIT_ANG_VT)

## Description
`Q_TAILSIT_ANG_VT` sets the "Nose Point" during the initial hover.

Standard tailsitters hover with the nose at 90 degrees (straight up). This parameter allows you to add an offset if your fuselage is naturally tilted or if you want the drone to hover with a slight forward lean.