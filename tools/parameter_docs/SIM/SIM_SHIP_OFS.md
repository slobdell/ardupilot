---
layout: parameter
name: SIM_SHIP_OFS
display_name: Simulation Ship Position Offset
description: The XYZ offset (in meters) of the simulated ship relative to the simulation origin.
default_value: 0
range: 
units: m
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_Ship.cpp#L42
---

# Simulation Ship Position Offset (SIM_SHIP_OFS)

## Description
`SIM_SHIP_OFS` allows you to move the simulated ship's starting point.

When simulating a moving platform (like a ship or truck), it is useful to be able to place it at a specific distance from the drone's "Home" or takeoff location.

*   **Format:** A vector (X, Y, Z) in meters.
*   **X:** North.
*   **Y:** East.
*   **Z:** Altitude (Negative is down/below home).

## Tuning & Behavior
*   **Default:** 0,0,0.
*   **Usage:** Set `Z` to a positive value (e.g. 5m) to simulate the ship's deck being higher than the water level or ground level.