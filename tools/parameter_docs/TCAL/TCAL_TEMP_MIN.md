---
layout: parameter
name: TCAL_TEMP_MIN
display_name: "Calibration temperature minimum"
description: "The lowest temperature (in degC) encountered during the successful learning of the thermal calibration model."
default_value: 0
range: null
units: "degC"
group: TCAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TempCalibration/AP_TempCalibration.cpp#L54
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Calibration temperature minimum (TCAL_TEMP_MIN)

## Description
This parameter records the starting (lowest) temperature of the range over which the temperature calibration model was learned. 

For a thermal correction model (like `BARO_EXP`) to be valid, it needs to be calculated based on data from a meaningful temperature change. This parameter, along with `TCAL_TEMP_MAX`, allows the pilot to verify that the learning process covered a wide enough range of temperatures to accurately model the sensor's drift.

## The Mathematics
During the learning phase (`TCAL_ENABLED=2`), the system records the initial temperature ($T_{start}$). Once the least-squares fit is calculated and the calibration is saved:

$$ TCAL\_TEMP\_MIN = T_{start} $$

This serves as a geofence for the calibration validity; corrections applied far outside the `MIN`/`MAX` range may be less accurate.

## The Engineer's View
In `AP_TempCalibration::calculate_calibration()` (`libraries/AP_TempCalibration/AP_TempCalibration.cpp`):
1.  The code calculates the optimal `baro_exponent`.
2.  Upon a successful calculation, it saves the `learn_temp_start` value into `temp_min`.
3.  The value is marked as `Volatile` in the parameter table, meaning it is expected to change during runtime as learning progresses.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Automatic:** This value is set automatically by the autopilot. You should not edit it manually.
*   **Verification:** If `TCAL_TEMP_MAX` minus `TCAL_TEMP_MIN` is less than 10 degrees, the calibration might not be robust enough for all seasons.

