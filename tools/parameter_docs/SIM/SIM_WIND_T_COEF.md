---
layout: parameter
name: SIM_WIND_T_COEF
display_name: Simulated Wind Type Coefficient
description: The friction coefficient for the wind gradient model.
default_value: 0.01
range: 0 1
units: 
group: SIM
visual_asset_id: sim_wind_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Wind Type Coefficient (SIM_WIND_T_COEF)

## Description
`SIM_WIND_T_COEF` defines the "Roughness" of the ground.

A higher value means the ground slows the wind down more, creating a steeper wind gradient (shear) near the surface.

## Tuning & Behavior
*   **Default Value:** 0.01.