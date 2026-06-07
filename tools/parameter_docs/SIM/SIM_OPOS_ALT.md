---
layout: parameter
name: SIM_OPOS_ALT
display_name: Simulated Original Position (Altitude)
description: The starting altitude (AMSL in meters) for the vehicle in the simulator.
default_value: 584.0
range: 0 10000
units: m
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Original Position (Altitude) (SIM_OPOS_ALT)

## Description
`SIM_OPOS_ALT` sets the spawn height Above Mean Sea Level (AMSL).

## Tuning & Behavior
*   **Default Value:** 584.0 m (Canberra elevation).
*   **Important:** If you change Lat/Lng to a coastal city but leave this at 584m, your drone will spawn 584m in the air!