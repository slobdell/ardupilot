---
layout: parameter
name: SIM_RATE_HZ
display_name: Simulation Loop Rate
description: The frequency (in Hz) at which the simulation physics engine runs.
default_value: 1200
range: 50 2000
units: Hz
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L215
---

# Simulation Loop Rate (SIM_RATE_HZ)

## Description
`SIM_RATE_HZ` sets the "Frame Rate" of the physics world.

The flight controller runs its main loop at a certain speed (e.g. 400Hz for Copter, 50Hz for Plane). The simulator must run faster than the flight controller to provide smooth sensor data.

*   **1200 (Default):** Good for most multirotors.
*   **400:** Sufficient for Plane or Rover.

## Tuning & Behavior
*   **Constraint:** Must be a multiple of the flight controller loop rate to avoid aliasing artifacts.
