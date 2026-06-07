---
layout: parameter
name: SIM_SHIP_PSIZE
display_name: Simulated Ship Pad Size
description: The size (in meters) of the landing pad markings on the ship deck.
default_value: 5
range: 1 50
units: m
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Ship.cpp#L25
---

# Simulated Ship Pad Size (SIM_SHIP_PSIZE)

## Description
`SIM_SHIP_PSIZE` controls the visual "H" or circle on the deck.