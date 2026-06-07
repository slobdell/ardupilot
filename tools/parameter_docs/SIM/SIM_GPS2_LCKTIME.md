---
layout: parameter
name: SIM_GPS2_LCKTIME
display_name: Simulation GPS 2 Lock Time
description: The time (in seconds) the second simulated GPS takes to acquire a 3D fix after boot-up.
default_value: 0
range: 0 120
units: s
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L125
---

# Simulation GPS 2 Lock Time (SIM_GPS2_LCKTIME)

## Description
`SIM_GPS2_LCKTIME` allows you to simulate a scenario where one GPS gets a fix much later than the other, testing the autopilot's primary/secondary switchover logic.
