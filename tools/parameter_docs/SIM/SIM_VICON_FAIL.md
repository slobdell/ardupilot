---
layout: parameter
name: SIM_VICON_FAIL
display_name: Simulation Vicon Failure
description: Simulates a failure of the external Vicon positioning system.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L538
---

# Simulation Vicon Failure (SIM_VICON_FAIL)

## Description
`SIM_VICON_FAIL` cuts the data feed from the external motion capture system.

This is critical for testing indoor drones. If the Vicon system crashes or the drone flies behind an obstacle, the EKF loses its primary position source. This parameter allows you to verify that the drone successfully fails over to Optical Flow or enters a safe landing mode.

*   **0: Healthy.**
*   **1: Failed.**
