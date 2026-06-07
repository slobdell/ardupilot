---
layout: parameter
name: SIM_MAG1_DEVID
display_name: Simulated Magnetometer 1 Device ID
description: The Device ID for the first simulated magnetometer.
default_value: 0
range: 0 16777216
units: 
group: SIM
visual_asset_id: imu_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Magnetometer 1 Device ID (SIM_MAG1_DEVID)

## Description
`SIM_MAG1_DEVID` sets the unique hardware identifier for the virtual compass.

This is usually read-only or managed by `SIM_MAG_SAVE_IDS`. However, developers can manually set this to test how the OS handles specific sensor types (e.g. simulating a specific I2C address conflict).

## Tuning & Behavior
*   **Default Value:** 0 (Auto-generated).