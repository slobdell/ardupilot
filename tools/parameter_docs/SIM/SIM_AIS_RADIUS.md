---
layout: parameter
name: SIM_AIS_RADIUS
display_name: Simulation AIS Radius
description: The radius (in meters) within which virtual maritime traffic (AIS targets) are injected into the simulation.
default_value: 0
range: 0 100000
units: m
group: SIM
visual_asset_id: physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L210
---

# Simulation AIS Radius (SIM_AIS_RADIUS)

## Description
`SIM_AIS_RADIUS` enables the simulation of other ships for maritime operations.

When set to a positive value, ArduPilot will generate "Fake" ships (AIS targets) within this distance. This allows you to test obstacle avoidance and traffic monitoring systems on boats and autonomous ships.