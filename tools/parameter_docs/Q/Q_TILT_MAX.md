---
layout: parameter
name: Q_TILT_MAX
display_name: Tilt Rotor Maximum Angle
description: The maximum angle (in degrees) of the tilt mechanism.
default_value: 45
range: 0 90
units: deg
group: Q
visual_asset_id: vtol_tilt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tilt Rotor Maximum Angle (Q_TILT_MAX)

## Description
`Q_TILT_MAX` defines the "Up" position for the tilt mechanism.

Usually, this is 90 degrees (vertical) for hover. However, some airframes (like the E-Flite Convergence) might have a different geometry.

## Tuning & Behavior
*   **Default Value:** 45 degrees.
*   **Recommendation:** Set to **90** for standard tilt-rotors.