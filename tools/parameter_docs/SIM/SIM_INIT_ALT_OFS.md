---
layout: parameter
name: SIM_INIT_ALT_OFS
display_name: Simulation Initial Alt Offset
description: An initial altitude offset (in meters) added to the drone's starting position in the simulation.
default_value: 0
range: -100 100
units: m
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L101
---

# Simulation Initial Alt Offset (SIM_INIT_ALT_OFS)

## Description
`SIM_INIT_ALT_OFS` allows you to start the simulation with the drone at a specific height above the ground. Useful for testing in-air resets or high-altitude drop launches.
