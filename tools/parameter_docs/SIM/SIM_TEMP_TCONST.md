---
layout: parameter
name: SIM_TEMP_TCONST
display_name: Simulation Temperature Time Constant
description: The time constant (in seconds) for board temperature warmup.
default_value: 30.0
range: 1 1000
units: s
group: SIM
visual_asset_id: imu_temp_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L141
---

# Simulation Temperature Time Constant (SIM_TEMP_TCONST)

## Description
`SIM_TEMP_TCONST` defines how fast the flight controller heats up in the simulator.

A lower value means the board reaches its operating temperature very quickly. A higher value simulates a large, heavy flight controller that takes a long time to stabilize.