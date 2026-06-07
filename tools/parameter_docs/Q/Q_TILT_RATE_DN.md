---
layout: parameter
name: Q_TILT_RATE_DN
display_name: Tilt Rotor Rate Down
description: The speed (in degrees per second) at which the rotors tilt down to the horizontal position.
default_value: 10
range: 10 300
units: deg/s
group: Q
visual_asset_id: vtol_tilt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tilt Rotor Rate Down (Q_TILT_RATE_DN)

## Description
`Q_TILT_RATE_DN` controls how fast the motors rotate forward.

This directly affects acceleration. A lower value gives a smoother, more gradual transition.

## Tuning & Behavior
*   **Default Value:** 10 deg/s.
*   **Recommendation:** Keep lower than `Q_TILT_RATE_UP` to prevent altitude loss during transition.