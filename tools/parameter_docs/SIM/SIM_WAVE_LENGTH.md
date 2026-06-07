---
layout: parameter
name: SIM_WAVE_LENGTH
display_name: Simulated Wave Length
description: The distance (in meters) between wave peaks in the simulation.
default_value: 10
range: 1 100
units: m
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Wave Length (SIM_WAVE_LENGTH)

## Description
`SIM_WAVE_LENGTH` sets the "Frequency" of the ocean swell.

Short wavelengths (e.g. 5m) create choppy, rapid rocking. Long wavelengths (e.g. 50m) create slow, graceful rises and falls.

## Tuning & Behavior
*   **Default Value:** 10 m.