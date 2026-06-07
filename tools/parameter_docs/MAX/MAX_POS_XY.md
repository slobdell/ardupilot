---
layout: parameter
name: MAX_POS_XY
display_name: Max XY Position Delta (Blimp)
description: Sets the maximum allowed horizontal position change per update cycle.
default_value: 0.2
range: 0.1 5.0
units: m/s
group: MAX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Blimp/Parameters.cpp#L237
---

# Max XY Position Delta (MAX_POS_XY)

## Description
`MAX_POS_XY` is a safety and smoothing parameter for **ArduBlimp**.

It limits how far the blimp's target position can "Jump" in a single update cycle. Because blimps have very high inertia and move slowly, sudden large changes in requested position can cause the control loops to become unstable. This parameter ensures that the requested path remains smooth and achievable by the blimp's low-thrust propulsion.

## Tuning & Behavior
*   **Default:** 0.2 m/s.
*   **Usage:** For larger, slower blimps, you may need to reduce this value to **0.1** to ensure smooth autonomous movement.