---
layout: parameter
name: SIM_WIND_T
display_name: Simulated Wind Type
description: Selects the wind gradient model (how wind speed changes with altitude).
default_value: 0
range: 0 2
units: 
group: SIM
visual_asset_id: sim_wind_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Wind Type (SIM_WIND_T)

## Description
`SIM_WIND_T` models how wind speed decreases as you get closer to the ground (due to ground friction).

*   **0: Square Law (Realistic).** Wind speed drops off naturally near the surface.
*   **1: None.** Constant wind speed at all altitudes.
*   **2: Linear.** Constant decrease from `SIM_WIND_T_ALT` down to zero.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Keep at **0** for realistic landing tests.