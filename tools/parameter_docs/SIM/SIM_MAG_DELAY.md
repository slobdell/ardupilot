---
layout: parameter
name: SIM_MAG_DELAY
display_name: Simulation Compass Delay
description: The latency (in milliseconds) introduced to the simulated magnetometer data.
default_value: 0
range: 0 100
units: ms
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L103
---

# Simulation Compass Delay (SIM_MAG_DELAY)

## Description
`SIM_MAG_DELAY` simulates slow compass updates or high-latency I2C buses.

Real compasses often sample slower than the EKF's loop rate. This parameter tests if the EKF can correctly align delayed compass samples with the corresponding IMU poses.
