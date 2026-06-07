---
layout: parameter
name: SIM_TWIST_TIME
display_name: Simulated Twist Time
description: The duration (in milliseconds) of the twist impulse.
default_value: 0
range: 0 10000
units: ms
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Twist Time (SIM_TWIST_TIME)

## Description
`SIM_TWIST_TIME` controls the duration of the rotational disturbance.

## Tuning & Behavior
*   **Default Value:** 0.