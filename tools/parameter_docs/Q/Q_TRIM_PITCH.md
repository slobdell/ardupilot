---
layout: parameter
name: Q_TRIM_PITCH
display_name: VTOL Pitch Trim
description: The pitch angle (in degrees) at which the QuadPlane hovers when there is no pilot input.
default_value: 0
range: -20 20
units: deg
group: Q
visual_asset_id: vtol_control_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# VTOL Pitch Trim (Q_TRIM_PITCH)

## Description
`Q_TRIM_PITCH` defines the "Neutral" attitude in hover.

If your QuadPlane naturally drifts forward while hovering, you can set a small positive trim to tilt the nose up slightly and stay stationary.

## Tuning & Behavior
*   **Default Value:** 0 degrees.
*   **Recommendation:** Use this to ensure the drone stays stationary in calm air with zero stick input.