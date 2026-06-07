---
layout: parameter
name: TECS_LAND_IGAIN
display_name: TECS Land Integrator Gain
description: The integrator gain for the Total Energy Control System used specifically during the landing phase.
default_value: 0
range: 0 0.5
units: 
group: TECS
visual_asset_id: tecs_tuning_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L221
---

# TECS Land Integrator Gain (TECS_LAND_IGAIN)

## Description
`TECS_LAND_IGAIN` allows you to have a different "Error Memory" for the final landing approach.

Normally, the flight controller uses `TECS_INTEG_GAIN`. However, during landing, ground effect and changing air density near the floor can cause persistent height errors. This parameter lets you set a dedicated integrator to trim out these errors for a more precise touchdown.

*   **0 (Default):** Use the standard `TECS_INTEG_GAIN`.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** If your plane consistently lands too short or too long due to wind/drag offsets, try setting this to **0.2**.