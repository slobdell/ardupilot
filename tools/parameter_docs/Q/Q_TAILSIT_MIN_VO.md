---
layout: parameter
name: Q_TAILSIT_MIN_VO
display_name: Tailsitter Min VO Speed
description: The minimum airspeed (in m/s) required for effective tailsitter vertical control.
default_value: 0
range: 0 10
units: m/s
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter Min VO Speed (Q_TAILSIT_MIN_VO)

## Description
`Q_TAILSIT_MIN_VO` defines the "Blind Speed." Below this airspeed, the autopilot relies entirely on VTOL motors for stabilization because the control surfaces (ailerons/elevons) are not yet effective.