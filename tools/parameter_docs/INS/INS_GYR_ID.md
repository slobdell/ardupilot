---
layout: parameter
name: INS_GYR_ID
display_name: Gyro ID
description: Unique hardware identifier for the first gyroscope.
default_value: 0
range: 
units: 
group: INS
visual_asset_id: ins_gyr_id_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L106
---

# Gyro ID (INS_GYR_ID)

## Description
`INS_GYR_ID` is a Read-Only parameter that stores the unique hardware ID of the first gyroscope (Gyro 1).

See [INS_ACC_ID](../INS_ACC_ID) for details on ID structure.

## The Mathematics
See [COMPASS_DEV_ID](../COMPASS_DEV_ID).

## The Engineer's View
See [INS_ACC_ID](../INS_ACC_ID).

## Tuning & Behavior
*   **Default Value:** 0 (Auto-Detect)