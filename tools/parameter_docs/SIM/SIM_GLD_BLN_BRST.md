---
layout: parameter
name: SIM_GLD_BLN_BRST
display_name: Simulation Balloon Burst
description: Simulates the sudden bursting of a high-altitude weather balloon for glider drop-test simulation.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: soaring_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Balloon.cpp#L25
---

# Simulation Balloon Burst (SIM_GLD_BLN_BRST)

## Description
`SIM_GLD_BLN_BRST` triggers the "Release" phase of a balloon glider test.

For drones that are carried to high altitudes by balloons, this parameter allows you to simulate the moment the balloon pops or the drone is released, instantly transitioning the physics model from buoyant ascent to aerodynamic glide.
