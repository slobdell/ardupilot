---
layout: parameter
name: SIM_GRPE_ENABLE
display_name: Simulation Gripper Enable
description: Enables the simulated robotic gripper for package delivery or object manipulation testing.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Gripper_EPM.cpp#L25
---

# Simulation Gripper Enable (SIM_GRPE_ENABLE)

## Description
`SIM_GRPE_ENABLE` activates a virtual robotic gripper.

This allows you to test "Pick and Place" missions in SITL. When enabled, the drone can physically attach to objects (like a virtual package) and carry them through the air, accounting for the added weight and inertia in the physics model.
