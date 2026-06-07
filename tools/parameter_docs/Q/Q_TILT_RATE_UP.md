---
layout: parameter
name: Q_TILT_RATE_UP
display_name: Tilt Rotor Rate Up
description: The speed (in degrees per second) at which the rotors tilt up to the vertical position.
default_value: 40
range: 10 300
units: deg/s
group: Q
visual_asset_id: vtol_tilt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tilt Rotor Rate Up (Q_TILT_RATE_UP)

## Description
`Q_TILT_RATE_UP` controls how fast the motors snap to vertical when you switch to QHOVER.

If this is too fast, the plane might balloon up (gain altitude rapidly). If too slow, the plane might stall before the motors can generate lift.

## Tuning & Behavior
*   **Default Value:** 40 deg/s.