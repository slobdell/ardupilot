---
layout: parameter
name: SIM_IMU_POS
display_name: Simulation IMU Position Offset
description: Defines the physical offset (in meters) of the IMU from the vehicle's center of gravity in the simulation.
default_value: 0
range: 0 5
units: m
group: SIM
visual_asset_id: imu_pos_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L148
---

# Simulation IMU Position Offset (SIM_IMU_POS)

## Description
`SIM_IMU_POS` simulates an IMU that is not mounted exactly at the center of gravity (COG).

When a drone rotates, any sensor away from the COG experiences "Centripetal Acceleration." If ArduPilot doesn't know about this offset (configured via `INS_POS_X/Y/Z`), the EKF will get confused and report incorrect velocity. This parameter allows you to test the compensation for these "Lever Arm" effects.