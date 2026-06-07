---
layout: parameter
name: SIM_SHIP_DSIZE
display_name: Simulated Ship Deck Size
description: The size (length/width in meters) of the landing deck on the simulated ship.
default_value: 10
range: 1 100
units: m
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Ship.cpp#L25
---

# Simulated Ship Deck Size (SIM_SHIP_DSIZE)

## Description
`SIM_SHIP_DSIZE` defines the dimensions of the helipad.

This affects the visual model and the collision detection. If the drone lands outside this area, it will fall into the "Water."

## Tuning & Behavior
*   **Default Value:** 10 m.