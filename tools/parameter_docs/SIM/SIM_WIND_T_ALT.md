---
layout: parameter
name: SIM_WIND_T_ALT
display_name: Simulated Wind Type Altitude
description: The altitude (in meters) above which the wind speed is constant (SIM_WIND_SPD). Below this altitude, the wind gradient model applies.
default_value: 60
range: 0 1000
units: m
group: SIM
visual_asset_id: sim_wind_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Wind Type Altitude (SIM_WIND_T_ALT)

## Description
`SIM_WIND_T_ALT` defines the "Boundary Layer" height.

Above this altitude, the wind speed is constant (`SIM_WIND_SPD`). Below this altitude, the wind slows down due to ground friction (if `SIM_WIND_T` is enabled).

## Tuning & Behavior
*   **Default Value:** 60 m.