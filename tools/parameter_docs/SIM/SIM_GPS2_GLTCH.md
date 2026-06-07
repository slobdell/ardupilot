---
layout: parameter
name: SIM_GPS2_GLTCH
display_name: Simulation GPS 2 Glitch
description: Adds a constant position offset (in meters) to the second simulated GPS.
default_value: 0
range: -100 100
units: m
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L115
---

# Simulation GPS 2 Glitch (SIM_GPS2_GLTCH)

## Description
`SIM_GPS2_GLTCH` allows you to test dual-GPS configurations by "breaking" the secondary receiver.

By injecting a glitch into only one GPS, you can verify that the EKF successfully switches to the healthy receiver (if configured for `GPS_AUTO_SWITCH = 1`).