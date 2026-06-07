---
layout: parameter
name: SIM_SB_ALT_TARG
display_name: Simulated StratoBlimp Target Altitude
description: The neutral buoyancy target altitude (in meters) for the StratoBlimp.
default_value: 1000
range: 0 40000
units: m
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_StratoBlimp.cpp#L25
---

# Simulated StratoBlimp Target Altitude (SIM_SB_ALT_TARG)

## Description
`SIM_SB_ALT_TARG` sets the "Zero Buoyancy" height for the StratoBlimp simulation. At this altitude, the blimp will naturally float without using its motors.

## Tuning & Behavior
*   **Default Value:** 1000 m.