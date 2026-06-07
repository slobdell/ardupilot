---
layout: parameter
name: INS_TCAL_OPTIONS
display_name: Temperature Calibration Options
description: Bitmask of options for the IMU temperature calibration system.
default_value: 0
range: 0 3
units: 
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L100
---

# Temperature Calibration Options (INS_TCAL_OPTIONS)

## Description
`INS_TCAL_OPTIONS` controls how the learned temperature calibration data is stored.

*   **Bit 0:** Persist Accel Calibration. Saves the accel offset/scale to the bootloader sector (if supported) so it survives a full parameter reset.
*   **Bit 1:** Persist Temp Calibration. Saves the `INS_TCAL` parameters to the bootloader sector.

## Tuning & Behavior
*   **Default Value:** 0.