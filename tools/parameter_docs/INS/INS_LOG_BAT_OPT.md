---
layout: parameter
name: INS_LOG_BAT_OPT
display_name: Batch Sampling Options
description: Bitmask of options for the IMU Batch Sampler (FFT logging).
default_value: 0
range: 0 31
units: 
group: INS
visual_asset_id: log_analysis_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_BatchSampler.cpp#L100
---

# Batch Sampling Options (INS_LOG_BAT_OPT)

## Description
`INS_LOG_BAT_OPT` configures the high-speed data recorder for vibration analysis.

To tune the Harmonic Notch Filter, you need to know exactly what frequencies your motors are vibrating at. Standard logs are too slow to capture this. The "Batch Sampler" captures short bursts of high-speed gyro data (1kHz+) and writes them to the log.

*   **Bit 0:** Sensor Selection. (0 = Gyro, 1 = Accel).
*   **Bit 1:** Message Type. (0 = Post-Filter, 1 = Pre-Filter).
*   **Bit 2:** Sample Rate. (0 = 1kHz, 1 = 2kHz+).

## Tuning & Behavior
*   **Default Value:** 0 (Gyro, Post-Filter).
*   **Recommendation:** Set to **0** for standard Gyro FFT analysis. Set to **2** (Bit 1) to see the "Raw" noise before any filters are applied.