---
layout: parameter
name: INS_GYR1_CALTEMP
display_name: Gyroscope 1 Calibration Temperature
description: The temperature (in degrees Celsius) recorded during the gyroscope calibration.
default_value: -300
range: -50 100
units: degC
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L100
---

# Gyroscope 1 Calibration Temperature (INS_GYR1_CALTEMP)

## Description
`INS_GYR1_CALTEMP` records the board temperature during gyro calibration.

Gyroscopes are sensitive to temperature changes. Knowing the temperature at which the zero-offset was determined allows the flight controller to better predict and correct for bias drift as the drone warms up or cools down.

## Tuning & Behavior
*   **Default Value:** -300 (Uncalibrated).
*   **Usage:** Automatically updated during calibration.