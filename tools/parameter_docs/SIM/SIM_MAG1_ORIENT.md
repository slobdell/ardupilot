---
layout: parameter
name: SIM_MAG1_ORIENT
display_name: Simulated Magnetometer 1 Orientation
description: Selects the orientation of the first simulated magnetometer relative to the vehicle frame.
default_value: 0
range: 0 38
units: 
group: SIM
visual_asset_id: imu_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Magnetometer 1 Orientation (SIM_MAG1_ORIENT)

## Description
`SIM_MAG1_ORIENT` sets the physical rotation of the virtual compass.

If you simulate a GPS/Compass module mounted with the arrow pointing backwards (Yaw 180), you must set this parameter to match.

## Tuning & Behavior
*   **Default Value:** 0 (None).