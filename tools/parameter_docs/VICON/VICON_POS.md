---
layout: parameter
name: VICON_POS
display_name: SITL Vicon Position
description: Position of the Vicon/Optitrack marker on the vehicle body frame (X, Y, Z).
default_value: 0
range: -5 5
units: m
group: VICON
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L548
---

# VICON_POS: SITL Vicon Position

## Description
Position of the Vicon/Optitrack marker on the vehicle body frame (X, Y, Z).

## Values
- **Range:** -5 to 5
- **Units:** m
- **Default:** 0, 0, 0

## Description
This parameter simulates the offset of an external motion capture target (like Vicon or Optitrack) in the SITL simulator.

- **Function:** If your simulated drone has the Vicon tracking balls mounted 10cm above the center of gravity, you would set the Z component of this parameter to **-0.1**.
- **Effect:** Allows testing of offset compensation logic in the EKF external navigation drivers.
