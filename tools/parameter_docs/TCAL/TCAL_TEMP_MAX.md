---
layout: parameter
name: TCAL_TEMP_MAX
display_name: "Calibration temperature maximum"
description: "The highest temperature (in degC) reached during the successful learning of the thermal calibration model."
default_value: 0
range: null
units: "degC"
group: TCAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TempCalibration/AP_TempCalibration.cpp#L65
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Calibration temperature maximum (TCAL_TEMP_MAX)

## Description
This parameter records the maximum temperature reached during a successful "Enable and Learn" session for temperature calibration. 

Thermal calibration works by watching how a sensor drifts as the flight controller heats up from its starting temperature to its steady-state operating temperature. `TCAL_TEMP_MAX` tells you the "Top End" of the data set used to create your correction model.

## The Mathematics
The system tracks the highest temperature ($T_{max}$) encountered while the vehicle was stationary and learning:

$$ TCAL\_TEMP\_MAX = T_{start} + (\text{LastValidIndex} \times \text{StepSize}) $$

The `StepSize` is typically **0.25°C**. This value defines the upper boundary of the "Trusted Zone" for the correction exponent.

## The Engineer's View
In `AP_TempCalibration::calculate_calibration()` (`libraries/AP_TempCalibration/AP_TempCalibration.cpp`):
1.  The code determines the current progress of the learning buffer (`learn_i`).
2.  It calculates the maximum temperature point reached in the data array.
3.  It updates `temp_max` and saves it to EEPROM along with the new calibration exponent.
4.  This provides a clear audit trail for the quality of the calibration.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Automatic:** Set by the system. Do not edit manually.
*   **Troubleshooting:** If this value is very close to `TCAL_TEMP_MIN`, it means the vehicle didn't have enough time to warm up (or the environment was too cold), and the resulting calibration might be inaccurate. Aim for at least a **10-15°C** difference between MIN and MAX for a high-fidelity calibration.

