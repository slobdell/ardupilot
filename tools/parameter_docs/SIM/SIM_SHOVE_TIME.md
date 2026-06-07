---
layout: parameter
name: SIM_SHOVE_TIME
display_name: Simulated Shove Time
description: The duration (in milliseconds) of the shove impulse.
default_value: 0
range: 0 10000
units: ms
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Shove Time (SIM_SHOVE_TIME)

## Description
`SIM_SHOVE_TIME` determines if the "Shove" is a punch or a push.

If set to 0, the velocity change is instantaneous (impulse). If set to a value (e.g. 2000 ms), the force is applied over that duration, simulating a sustained wind gust or thruster firing.

## Tuning & Behavior
*   **Default Value:** 0.