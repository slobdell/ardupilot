---
layout: parameter
name: SIM_PLD_SHIP
display_name: Simulation Landing Ship
description: Enables the simulation of a moving ship deck for precision landing and maritime mission testing.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: precland_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L120
---

# Simulation Landing Ship (SIM_PLD_SHIP)

## Description
`SIM_PLD_SHIP` activates a moving landing platform.

This is the primary tool for testing Maritime operations. When enabled, SITL simulates a ship that pitches, rolls, and travels through the water. You can then test if your drone successfully performs a precision landing on a moving deck using the [PLND_ENABLED](../PL/PLND_ENABLED.html) logic.