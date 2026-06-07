---
layout: parameter
name: INS_TCAL_ACC1
display_name: Accelerometer 1 Temp Coeff
description: The 1st-order linear temperature compensation coefficient for Accel 1.
default_value: 0
range: -10 10
units: 
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_tempcal.cpp#L95
---

# Accelerometer 1 Temp Coeff (INS_TCAL_ACC1)

## Description
`INS_TCAL_ACC1` is a learned calibration value.

During a "Temperature Calibration," the flight controller heats up (either naturally or via `BRD_HEAT_TARG`) while stationary. It measures how the accelerometer bias shifts with temperature and calculates this slope coefficient to subtract the thermal error in flight.

## Tuning & Behavior
*   **Default Value:** 0 (No compensation).
*   **Usage:** Automatically populated by the temp calibration routine.