---
layout: parameter
name: TECS_TKOFF_IGAIN
display_name: TECS Takeoff Integrator Gain
description: The integrator gain for the Total Energy Control System used specifically during the takeoff phase.
default_value: 0
range: 0 0.5
units: 
group: TECS
visual_asset_id: tecs_tuning_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L200
---

# TECS Takeoff Integrator Gain (TECS_TKOFF_IGAIN)

## Description
`TECS_TKOFF_IGAIN` allows you to have a different "Memory" setting for takeoff.

Normally, `TECS_INTEG_GAIN` handles long-term errors. However, during takeoff, the dynamics change rapidly (ground effect, rapid acceleration). This parameter overrides the standard gain to ensure the plane tracks the climb rate accurately during this critical phase.

*   **0 (Default):** Use `TECS_INTEG_GAIN`.
*   **> 0:** Use this specific gain for takeoff.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** If your plane tends to overshoot or undershoot the climb angle right after launch, try setting this to **0.4**.