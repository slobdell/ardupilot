---
layout: parameter
name: SIM_DRIFT_TIME
display_name: Simulation GPS Drift Time
description: The time constant (in seconds) for the simulated GPS position drift.
default_value: 5
range: 1 50
units: s
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L103
---

# Simulation GPS Drift Time (SIM_DRIFT_TIME)

## Description
`SIM_DRIFT_TIME` controls how often the GPS drift changes direction.

See [SIM_DRIFT_SPEED](SIM_DRIFT_SPEED.html).
