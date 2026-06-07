---
layout: parameter
name: SIM_VICON_YAWERR
display_name: Simulation Vicon Yaw Error
description: Adds a constant yaw offset (in degrees) to the reported Vicon heading.
default_value: 0
range: -180 180
units: deg
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L539
---

# Simulation Vicon Yaw Error (SIM_VICON_YAWERR)

## Description
`SIM_VICON_YAWERR` simulates a misalignment between the Vicon system's north and the drone's IMU north. This tests the EKF's ability to handle rotational offsets in external position data.
