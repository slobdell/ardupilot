---
layout: parameter
name: INS_ACC_ID
display_name: Accelerometer ID
description: Unique hardware identifier for the first accelerometer.
default_value: 0
range: 
units: 
group: INS
visual_asset_id: ins_acc_id_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L313
---

# Accelerometer ID (INS_ACC_ID)

## Description
`INS_ACC_ID` is a Read-Only parameter that stores the unique hardware ID of the first accelerometer (Accel 1).

It is used to identify the sensor and associate calibration data (offsets/scaling) with the specific physical hardware.

## The Mathematics
See [COMPASS_DEV_ID](../COMPASS_DEV_ID) for ID packing details (Bus type, Bus number, Address).

## The Engineer's View
Populated during `AP_InertialSensor::init()`.
If set to 0, the system re-detects the sensor on the next boot.
Usually, this ID matches `INS_GYR_ID` if the accelerometer and gyroscope are part of the same 6-axis IMU chip (e.g., MPU6000, ICM20602), though the `dev_type` bits might differ slightly depending on the driver implementation.

## Tuning & Behavior
*   **Default Value:** 0 (Auto-Detect)
*   **Recommendation:** Do not touch. If you replace the flight controller, this will update automatically.