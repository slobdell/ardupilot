---
layout: parameter
name: Q_THROTTLE_EXPO
display_name: Pilot Throttle Exponential
description: The amount of exponential curvature applied to the pilot's throttle stick input in VTOL modes.
default_value: 0
range: 0 1
units: 
group: Q
visual_asset_id: vtol_control_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Pilot Throttle Exponential (Q_THROTTLE_EXPO)

## Description
`Q_THROTTLE_EXPO` makes the throttle stick less sensitive around the middle (hover) position.

This helps the pilot maintain a steady hover by preventing small accidental stick movements from causing the drone to climb or descend.

## Tuning & Behavior
*   **0:** Linear.
*   **Recommendation:** Match your `MOT_THST_EXPO` if you want a consistent feel.