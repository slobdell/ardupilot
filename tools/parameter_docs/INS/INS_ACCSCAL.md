---
layout: parameter
name: INS_ACCSCAL
display_name: Accelerometer Z Scale Factor
description: The calibrated scaling factor for the accelerometer Z-axis.
default_value: 1.0
range: 0.8 1.2
units: 
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_Params.cpp#L40
---

# Accelerometer Z Scale Factor (INS_ACCSCAL)

## Description
`INS_ACCSCAL` corrects the "Gain" of the accelerometer.

If you tip the drone 90 degrees, the Z-axis should read 0G. If it reads 0.1G, the scale factor is wrong. This parameter is calculated automatically during the 6-point calibration to ensuring that 1G really means 1G.

## Tuning & Behavior
*   **Default Value:** 1.0 (No correction).
*   **Usage:** Automatically updated during calibration.