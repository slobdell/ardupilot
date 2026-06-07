---
layout: parameter
name: Q_PLT_Y_EXPO
display_name: Pilot Yaw Exponential
description: The amount of exponential curvature applied to the pilot's yaw stick input.
default_value: 0
range: 0 1
units: 
group: Q
visual_asset_id: vtol_control_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Pilot Yaw Exponential (Q_PLT_Y_EXPO)

## Description
`Q_PLT_Y_EXPO` makes the yaw stick less sensitive around the center point.

This allows for very fine heading corrections with small stick movements, while still providing full rotation speed at the stick edges.

## Tuning & Behavior
*   **0:** Linear control (same sensitivity everywhere).
*   **0.5:** Moderate expo.
*   **Recommendation:** Use **0.15 - 0.25** for a natural control feel.