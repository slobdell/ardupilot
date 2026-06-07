---
layout: parameter
name: INS_TCAL1_TMAX
display_name: IMU1 Temperature Calibration Max
description: The maximum temperature (in degrees Celsius) that the calibration is valid for.
default_value: 0
range: 0 85
units: degC
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_tempcal.cpp#L100
---

# IMU1 Temperature Calibration Max (INS_TCAL1_TMAX)

## Description
`INS_TCAL1_TMAX` records the hottest temperature reached during calibration.

If the flight controller gets hotter than this during flight, the EKF will stop using the temperature compensation to avoid extrapolating into unknown territory.

## Tuning & Behavior
*   **Default Value:** 0 (Uncalibrated).
*   **Recommendation:** Do not edit manually.