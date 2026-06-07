---
layout: parameter
name: SIM_TERRAIN
display_name: Simulation Terrain Enable
description: Enables the use of terrain data in the simulation, allowing the ground altitude to vary based on location.
default_value: 1
range: 0 1
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L114
---

# Simulation Terrain Enable (SIM_TERRAIN)

## Description
`SIM_TERRAIN` turns on the "Ground."

When enabled, SITL downloads SRTM terrain data (just like the real flight controller) and uses it to calculate the ground height at the drone's current location. This is essential for testing terrain following, rangefinder altimetry, and crash detection.

*   **0: Disabled.** The world is flat at altitude 0.
*   **1: Enabled.** The ground height varies.
