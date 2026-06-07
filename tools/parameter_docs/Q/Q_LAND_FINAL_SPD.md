---
layout: parameter
name: Q_LAND_FINAL_SPD
display_name: QuadPlane Land Final Speed
description: The descent speed (in m/s) used below Q_LAND_FINAL_ALT.
default_value: 0.5
range: 0.1 2.0
units: m/s
group: Q
visual_asset_id: vtol_land_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Land Final Speed (Q_LAND_FINAL_SPD)

## Description
`Q_LAND_FINAL_SPD` is the "Touchdown Velocity."

*   **0.5 (Default):** 0.5 m/s. Safe for most skids and wheels.
*   **0.3:** Very gentle.
*   **1.0:** Firm landing.

## Tuning & Behavior
*   **Default Value:** 0.5 m/s.
*   **Recommendation:** If you land on uneven ground, keep this low. If you land on a moving boat, you might need it higher to "stick" the landing.