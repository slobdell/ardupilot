---
layout: parameter
name: SIM_TETH_LINELEN
display_name: Simulated Tether Length
description: The total length (in meters) of the tether cable.
default_value: 100
range: 10 1000
units: m
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Tether.cpp#L25
---

# Simulated Tether Length (SIM_TETH_LINELEN)

## Description
`SIM_TETH_LINELEN` sets the maximum reach of the cable.

If the drone flies further than this distance from the tether anchor point, it will be physically jerked back by the "Rope," potentially causing a crash or oscillation.

## Tuning & Behavior
*   **Default Value:** 100 m.