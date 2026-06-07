---
layout: parameter
name: SIM_GLD_BLN_RATE
display_name: Simulated Glider/Balloon Rate
description: The physics update rate (in Hz) for the simulated glider or balloon model.
default_value: 0
range: 0 100
units: Hz
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Glider/Balloon Rate (SIM_GLD_BLN_RATE)

## Description
`SIM_GLD_BLN_RATE` sets the physics resolution for slow-moving airframes like gliders and weather balloons.