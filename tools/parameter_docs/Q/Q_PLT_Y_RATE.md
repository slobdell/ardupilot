---
layout: parameter
name: Q_PLT_Y_RATE
display_name: Pilot Commanded Yaw Rate
description: The maximum yaw rate (in deg/s) commanded by full pilot stick deflection in VTOL modes.
default_value: 0
range: 0 500
units: deg/s
group: Q
visual_asset_id: vtol_control_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Pilot Commanded Yaw Rate (Q_PLT_Y_RATE)

## Description
`Q_PLT_Y_RATE` sets how fast the drone spins when the pilot pushes the rudder stick.

*   **0 (Default):** Use `Q_YAW_RATE_MAX`.
*   **Value:** Override with a specific rate for pilot input.