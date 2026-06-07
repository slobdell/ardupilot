---
layout: parameter
name: SIM_FLOW_POS
display_name: Simulation Optical Flow Position
description: The physical offset (in meters) of the optical flow sensor from the vehicle's center of gravity in the simulation.
default_value: 0
range: 0 5
units: m
group: SIM
visual_asset_id: imu_pos_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L120
---

# Simulation Optical Flow Position (SIM_FLOW_POS)

## Description
`SIM_FLOW_POS` defines where the optical flow sensor is mounted in the simulator.

Just like the IMU and GPS, if the optical flow sensor is away from the COG, it will experience extra movement during rotations. This parameter tests the flight controller's ability to use the [FLOW_POS_X/Y/Z](../FL/FLOW_POS_X.html) parameters to compensate for these "lever arm" effects.