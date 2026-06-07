---
layout: parameter
name: ACRO_EXPO
display_name: Acro Mode Exponential
description: Applies a non-linear "Expo" curve to roll and pitch inputs in ACRO mode to soften center-stick response.
default_value: 0.3
range: 0 1.0
units: 
group: ACRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Acro Mode Exponential (ACRO_EXPO)

## Description
`ACRO_EXPO` makes the drone feel less "twitchy" when the control sticks are near the center.

In **ACRO** mode, the drone rotates based on stick position. Without Expo (0), the response is linear—small movements result in immediate rotation. This can make steady flight difficult. Setting an Expo value (like **0.3**) flattens the curve near the center, providing fine control for precision flying, while still allowing for full-speed flips and rolls when the stick is pushed to the edge.

## Tuning & Behavior
*   **0:** Linear response (Very sensitive).
*   **0.3 (Default):** Standard aerobatic feel.
*   **0.5+:** Very "soft" center stick, very aggressive at the edges.
*   **Recommendation:** Start at **0.3** and increase if you find yourself accidentally over-correcting during smooth flight.