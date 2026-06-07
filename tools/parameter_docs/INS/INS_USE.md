---
layout: parameter
name: INS_USE
display_name: Use first IMU
description: Controls whether the first IMU is used for attitude, velocity, and position estimation.
default_value: 1
range: 0 1
units: 
group: INS
visual_asset_id: ins_use_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L307
---

# Use first IMU (INS_USE)

## Description
`INS_USE` toggles the **first** IMU (gyro/accel) for state estimation.

*   **1 (Enabled):** The EKF can use this sensor for flight.
*   **0 (Disabled):** The sensor is initialized and logged, but the EKF will ignore its data.

## The Mathematics
The EKF runs multiple "lanes" (instances). If `INS_USE` is 0, the lane corresponding to this sensor is flagged as "Not Active" or "Unhealthy" (depending on implementation details in EKF2/EKF3).

## The Engineer's View
Used in `AP_InertialSensor::use_gyro()` and `use_accel()`.
If set to 0, the driver still runs (unlike `INS_ENABLE_MASK`), but `get_gyro_health()` effectively returns false for the purpose of fusion.

## Tuning & Behavior
*   **Default Value:** 1
*   **Use Case:** If IMU 1 is noisy (e.g., resonance on the specific chip), you can set `INS_USE = 0` to force the EKF to rely on IMU 2 and 3.