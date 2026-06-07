---
layout: parameter
name: TCAL_ENABLED
display_name: "Temperature calibration enable"
description: "Master enable for the temperature calibration system. Controls whether learned thermal correction values are applied to sensors."
default_value: 0
range: 0 2
units: "Option"
group: TCAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TempCalibration/AP_TempCalibration.cpp#L45
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Temperature calibration enable (TCAL_ENABLED)

## Description
This parameter enables the advanced temperature calibration system. Many MEMS sensors (especially barometers like the ICM-20789) suffer from "thermal drift," where the reported values change significantly as the electronics heat up during operation.

Setting this parameter allows the autopilot to either "Learn" a correction model for your specific hardware or "Apply" previously learned corrections to ensure stable altitude and attitude estimates across varying temperatures.

## The Mathematics
The system operates as a simple state machine:

*   **0: Disabled.** No thermal corrections are applied.
*   **1: Enabled (Use Learned).** The autopilot applies the learned exponent (e.g., `BARO_EXP`) to the raw sensor data.
*   **2: Enable and Learn.** While the vehicle is stationary and disarmed, the system records sensor drift vs. temperature and uses a least-squares fit to calculate the correction model. Once a sufficient temperature range is covered, it updates the calibration parameters.

## The Engineer's View
In `AP_TempCalibration.cpp`, the `update()` function runs at 10Hz:
1.  If set to `TC_ENABLE_LEARN` (2), it calls `learn_calibration()`. This requires the vehicle to be perfectly still (`AP::ins().is_still()`) and disarmed.
2.  If set to `TC_ENABLE_USE` (1) or `TC_ENABLE_LEARN` (2), it calls `apply_calibration()`.
3.  The actual correction is applied to the barometer driver via `baro.set_pressure_correction()`.

## Tuning & Behavior
*   **Learning Procedure:** To calibrate a new board, set `TCAL_ENABLED=2` and let the vehicle sit stationary for 10-15 minutes while it warms up.
*   **Verification:** Check the `TCAL_TEMP_MIN` and `TCAL_TEMP_MAX` parameters to see the range covered during learning.
*   **Final Step:** Once you are happy with the stability, you can set this to **1** to stop the learning process and just use the saved model.

