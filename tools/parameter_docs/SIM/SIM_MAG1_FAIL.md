---
layout: parameter
name: SIM_MAG1_FAIL
display_name: Simulation Compass 1 Failure
description: Simulates a total hardware failure of the first compass.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L129
---

# Simulation Compass 1 Failure (SIM_MAG1_FAIL)

## Description
`SIM_MAG1_FAIL` kills the first compass sensor.

*   **0: Healthy.**
*   **1: Failed.** The sensor stops reporting data.

## Tuning & Behavior
*   **Testing:** Use this to verify that your drone successfully fails over to the second compass (if available) or switches to GSF (GPS-based yaw) without crashing.
