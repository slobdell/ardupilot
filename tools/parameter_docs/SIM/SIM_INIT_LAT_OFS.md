---
layout: parameter
name: SIM_INIT_LAT_OFS
display_name: Simulated Initial Latitude Offset
description: Shifts the GPS coordinate system by this latitude offset (in degrees) relative to the physics origin.
default_value: 0
range: -1 1
units: deg
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Initial Latitude Offset (SIM_INIT_LAT_OFS)

## Description
`SIM_INIT_LAT_OFS` allows you to test what happens if the "map" shifts under the drone.

It adds a constant offset to the GPS position reported by the simulator, effectively moving the world origin.

## Tuning & Behavior
*   **Default Value:** 0.