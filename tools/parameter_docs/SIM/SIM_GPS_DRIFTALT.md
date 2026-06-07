---
layout: parameter
name: SIM_GPS_DRIFTALT
display_name: Simulation GPS Altitude Drift
description: Adds a constant altitude drift (in m/s) to the simulated GPS reading.
default_value: 0
range: -1 1
units: m/s
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L112
---

# Simulation GPS Altitude Drift (SIM_GPS_DRIFTALT)

## Description
`SIM_GPS_DRIFTALT` simulates the atmospheric drift often seen in low-cost GPS modules.

If the GPS reports that the drone is slowly "climbing" or "sinking" while it is actually sitting on the ground, the EKF must decide whether to believe the GPS or the Barometer. This parameter allows you to test that weighting logic.
