---
layout: parameter
name: Q_TILT_ENABLE
display_name: Tilt Rotor Enable
description: Master switch to enable tilt-rotor support for QuadPlanes.
default_value: 0
range: 0 1
units: 
group: Q
visual_asset_id: vtol_tilt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tilt Rotor Enable (Q_TILT_ENABLE)

## Description
`Q_TILT_ENABLE` activates the logic for VTOLs that rotate their motors.

Unlike a standard QuadPlane (which has separate lift and push motors), a Tilt Rotor uses servos to point the motors up for hover and forward for flight.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Enabled.
*   **Reboot Required:** Yes.