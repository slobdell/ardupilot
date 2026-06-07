---
layout: parameter
name: MANUAL_STR_EXPO
display_name: Manual Steering Exponential
description: Applies a non-linear "Expo" curve to Rover steering in MANUAL mode to soften center-stick response.
default_value: 0
range: -0.5 0.95
units: 
group: MANUAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/Parameters.cpp#L682
---

# Manual Steering Exponential (MANUAL_STR_EXPO)

## Description
`MANUAL_STR_EXPO` makes Rover steering feel less "twitchy" when the control sticks are near the center.

Without Expo (0), the steering is linear—small stick movements result in immediate, sharp turns. This can make high-speed driving difficult. Setting a positive Expo value flattens the curve near the center, providing fine control for straight-line driving and subtle corrections, while still allowing for full lock-to-lock steering when the stick is pushed to the edge.

## Tuning & Behavior
*   **0:** Linear response (Standard).
*   **Positive (0.1 to 0.95):** Softer center-stick feel.
*   **Negative (-0.1 to -0.5):** Sharper center-stick feel (Aggressive).
*   **Recommendation:** Start with **0.2** for high-speed rovers to improve stability.