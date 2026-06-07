---
layout: parameter
name: Q_WVANE_LAND
display_name: QuadPlane Weathervane Land
description: Enables weathervaning during the landing phase.
default_value: 0
range: 0 1
units: 
group: Q
visual_asset_id: vtol_weathervane_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Weathervane Land (Q_WVANE_LAND)

## Description
`Q_WVANE_LAND` allows the drone to pivot into the wind while descending for a landing.

*   **0:** Disabled (Maintains approach heading).
*   **1:** Enabled (Turns into wind).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Enable this if you fly in strong winds, as landing sideways can tip the drone over.