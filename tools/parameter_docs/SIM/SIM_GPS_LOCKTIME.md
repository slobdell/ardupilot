---
layout: parameter
name: SIM_GPS_LOCKTIME
display_name: Simulation GPS Lock Time
description: The time (in seconds) the simulated GPS takes to acquire a 3D fix after boot-up.
default_value: 0
range: 0 120
units: s
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L115
---

# Simulation GPS Lock Time (SIM_GPS_LOCKTIME)

## Description
`SIM_GPS_LOCKTIME` simulates a "Cold Start."

In SITL, the GPS usually gets a fix instantly. This parameter forces the autopilot to wait for a realistic duration before the GPS reports a valid position. Useful for testing pre-arm procedures.
