---
layout: parameter
name: SIM_VICON_POS
display_name: Simulation Vicon Position Offset
description: The physical offset (in meters) of the Vicon (External Position) system marker from the vehicle's center of gravity.
default_value: 0
range: 0 5
units: m
group: SIM
visual_asset_id: imu_pos_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L533
---

# Simulation Vicon Position Offset (SIM_VICON_POS)

## Description
`SIM_VICON_POS` defines where the "Vicon Marker" is attached to the drone.

In high-precision indoor flight, the position is often reported by an external camera system (Vicon/Optitrack). This parameter allows you to test the compensation for markers that are not mounted at the COG.