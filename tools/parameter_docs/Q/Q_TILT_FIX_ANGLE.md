---
layout: parameter
name: Q_TILT_FIX_ANGLE
display_name: Tilt Rotor Fixed Angle
description: The angle (in degrees) to hold the tilt rotors when disarmed or in a fixed-wing mode on the ground.
default_value: 0
range: 0 90
units: deg
group: Q
visual_asset_id: vtol_tilt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tilt Rotor Fixed Angle (Q_TILT_FIX_ANGLE)

## Description
`Q_TILT_FIX_ANGLE` sets the "Park Position" for the motors.

When you disarm, do you want the motors pointing up (90) to keep props out of the grass, or forward (0) to look streamlined? This parameter controls that behavior.

## Tuning & Behavior
*   **Default Value:** 0.