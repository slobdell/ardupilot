---
layout: parameter
name: Q_AUTOTUNE_AGGR
display_name: QuadPlane Autotune Aggressiveness
description: Sets the desired sharpness of the tune produced by QAUTOTUNE.
default_value: 0.1
range: 0.05 0.15
units: 
group: Q
visual_asset_id: autotune_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Autotune Aggressiveness (Q_AUTOTUNE_AGGR)

## Description
`Q_AUTOTUNE_AGGR` tells the autotuner how "twitchy" you want the final tune to be.

*   **0.05 (Soft):** Very smooth, slow response. Good for aerial photography and large, flexible frames.
*   **0.1 (Medium):** Good all-around performance.
*   **0.15 (Sharp):** Very aggressive. Good for small, rigid frames. Risk of oscillation if the frame isn't stiff enough.

## Tuning & Behavior
*   **Default Value:** 0.1
*   **Recommendation:** Start at **0.075 or 0.1**.