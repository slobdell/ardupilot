---
layout: parameter
name: INS_RAW_LOG_OPT
display_name: Raw IMU Logging Options
description: Controls the logging of raw high-rate IMU data for vibration analysis and filter tuning.
default_value: 0
range: 0 65535
units: 
group: INS
visual_asset_id: log_analysis_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L100
---

# Raw IMU Logging Options (INS_RAW_LOG_OPT)

## Description
`INS_RAW_LOG_OPT` enables high-speed data recording from the IMUs.

By default, ArduPilot logs filtered IMU data at a reduced rate. This parameter allows you to log the raw, unfiltered sensor data at full speed (up to 4kHz depending on hardware). This is critical for FFT analysis, notch filter tuning, and diagnosing high-frequency vibration issues.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Log Primary Gyro/Accel.
*   **2:** Log Secondary Gyro/Accel.
*   **4:** Log Tertiary Gyro/Accel.
*   **7:** Log All IMUs.

## Recommendation
Only enable this for short debugging flights. Raw logging consumes significant SD card bandwidth and can fill the logs quickly.