---
layout: parameter
name: TCAL_BARO_EXP
display_name: "Temperature Calibration barometer exponent"
description: "Learned exponent for barometer temperature correction"
default_value: 0
range: 
units: ""
group: TCAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TempCalibration/AP_TempCalibration.cpp#L73
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TempCalibration/AP_TempCalibration.h#L56
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Temperature Calibration barometer exponent (TCAL_BARO_EXP)

## Description
This parameter represents the **Learned Exponent** for the barometer's temperature calibration curve. It is automatically adjusted by the `AP_TempCalibration` library when the vehicle is disarmed and undergoing temperature changes (e.g., self-heating after boot). It ensures that the altitude reading remains stable even as the autopilot's temperature fluctuates.

## The Mathematics
The calibration model corrects the raw pressure reading based on the temperature difference from a reference point:
$$ P_{corrected} \approx P_{raw} + \text{TCAL\_BARO\_EXP} \cdot (T - T_{cal}) $$
*(Note: This is a simplified representation of the internal polynomial fit).*

## The Engineer's View
Defined in `libraries/AP_TempCalibration/AP_TempCalibration.cpp`. It is part of the `AP_TempCalibration` system which monitors IMU and Baro drift vs. temperature.
*   **Do Not Edit:** This value is learned. Manually changing it will invalidate the calibration.
*   **Reset:** Setting to 0 resets the learning for this term.

## Tuning & Behavior
*   **Default Value:** 0
*   **Behavior:** Should converge to a non-zero value over time if the board has significant temperature sensitivity.