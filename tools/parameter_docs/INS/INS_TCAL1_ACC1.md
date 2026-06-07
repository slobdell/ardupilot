---
layout: parameter
name: INS_TCAL1_ACC1
display_name: IMU1 Temperature Cal Accel 1
description: The 1st order (Linear) temperature coefficient for the Z-axis accelerometer.
default_value: 0
range: -10 10
units: 
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_tempcal.cpp#L95
---

# IMU1 Temperature Cal Accel 1 (INS_TCAL1_ACC1)

## Description
`INS_TCAL1_ACC1` is the linear component of the temperature compensation curve for the first IMU's accelerometer.

As the flight controller heats up (due to the STM32 processor or sunny weather), the accelerometer reading can drift. This parameter corrects that drift based on the difference between the current temperature and the calibration reference temperature (35°C).

## The Mathematics
The correction applied to the sensor reading is a 3rd-order polynomial:

$$ \text{Correction} = \left( C_1 \Delta T + C_2 \Delta T^2 + C_3 \Delta T^3 \right) \times 10^{-6} $$

Where:
*   $C_1$ is `INS_TCAL1_ACC1`
*   $\Delta T = T_{current} - 35^\circ C$
*   The factor $10^{-6}$ scales the parameter values (which are stored as large integers for easier GCS editing) back to their physical units.

## The Engineer's View
Defined in `AP_InertialSensor_tempcal.cpp`.
This parameter is learned automatically when you run the "Temperature Calibration" routine. You should generally **not** edit this manually unless you are manually fitting a curve to logged data.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Perform a temperature calibration if you see the EKF attitude drift significantly during the first few minutes of flight (warm-up).
