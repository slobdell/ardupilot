---
layout: parameter
name: SIM_SHIP_SPEED
display_name: Simulated Ship Speed
description: The forward speed (in m/s) of the simulated ship.
default_value: 0
range: 0 15
units: m/s
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Ship.cpp#L25
---

# Simulated Ship Speed (SIM_SHIP_SPEED)

## Description
`SIM_SHIP_SPEED` sets how fast the target vessel moves.

## Tuning & Behavior
*   **Default Value:** 0 m/s.
*   **Recommendation:** Set to **5-10 m/s** to test the drone's ability to track and land on a moving deck.