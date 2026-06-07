---
layout: parameter
name: INS_TCAL1_ACC3
display_name: IMU1 Temperature Cal Accel 3
description: The 3rd order (Cubic) temperature coefficient for the Z-axis accelerometer.
default_value: 0
range: -10 10
units: 
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_tempcal.cpp#L95
---

# IMU1 Temperature Cal Accel 3 (INS_TCAL1_ACC3)

## Description
`INS_TCAL1_ACC3` is the cubic component of the temperature compensation curve.

## The Mathematics
$$ \text{Correction} = \left( C_1 \Delta T + C_2 \Delta T^2 + C_3 \Delta T^3 \right) \times 10^{-6} $$

Where $C_3$ is `INS_TCAL1_ACC3`.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Do not edit manually.
