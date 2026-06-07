---
layout: parameter
name: SIM_MAG1_SCALING
display_name: Simulated Magnetometer 1 Scaling
description: A scaling factor applied to the first simulated magnetometer to simulate calibration errors.
default_value: 1.0
range: 0.5 1.5
units: 
group: SIM
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Magnetometer 1 Scaling (SIM_MAG1_SCALING)

## Description
`SIM_MAG1_SCALING` simulates a mis-calibrated compass.

By setting this to 1.1 or 0.9, you can test if the "Compass Motel" (onboard calibration) or the EKF can learn and correct for the scale factor error.

## Tuning & Behavior
*   **Default Value:** 1.0.