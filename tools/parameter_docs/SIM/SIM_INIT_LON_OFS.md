---
layout: parameter
name: SIM_INIT_LON_OFS
display_name: Simulated Initial Longitude Offset
description: Shifts the GPS coordinate system by this longitude offset (in degrees) relative to the physics origin.
default_value: 0
range: -1 1
units: deg
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Initial Longitude Offset (SIM_INIT_LON_OFS)

## Description
`SIM_INIT_LON_OFS` shifts the GPS longitude origin. See `SIM_INIT_LAT_OFS`.

## Tuning & Behavior
*   **Default Value:** 0.