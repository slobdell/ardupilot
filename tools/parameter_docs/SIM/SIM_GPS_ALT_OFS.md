---
layout: parameter
name: SIM_GPS_ALT_OFS
display_name: Simulation GPS Altitude Offset
description: Adds a constant altitude offset (in meters) to the simulated GPS reading.
default_value: 0
range: -100 100
units: m
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L121
---

# Simulation GPS Altitude Offset (SIM_GPS_ALT_OFS)

## Description
`SIM_GPS_ALT_OFS` injects a constant error into the GPS altitude. This is used to test if the EKF can handle significant differences between its primary altitude source (usually Barometer) and the GPS.