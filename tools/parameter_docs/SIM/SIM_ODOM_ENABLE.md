---
layout: parameter
name: SIM_ODOM_ENABLE
display_name: Simulation Odometry Enable
description: Enables the simulated visual odometry data stream.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L507
---

# Simulation Odometry Enable (SIM_ODOM_ENABLE)

## Description
`SIM_ODOM_ENABLE` activates a virtual Visual Odometry (VO) sensor.

This simulates a camera-based system (like an Intel Realsense) that tracks the drone's position by looking at the ground. Useful for testing autonomous navigation in GPS-denied environments without needing a full Vicon setup.
