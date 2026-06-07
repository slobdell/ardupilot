---
layout: parameter
name: BARO_EXP
display_name: Baro Temperature Correction Exponent
description: Learned power-function exponent used to correct barometer pressure drift as temperature changes.
default_value: 0
range: null
units: "Exponent"
group: BARO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TempCalibration/AP_TempCalibration.cpp#L73
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Baro Temperature Correction Exponent (BARO_EXP)

## Description
This parameter is part of ArduPilot's advanced temperature calibration system. Many barometric sensors exhibit a "drift" where the reported pressure changes simply because the sensor is heating up, even if the altitude remains constant. This is a common issue with sensors like the ICM-20789.

`BARO_EXP` stores a learned mathematical exponent that models this drift. When temperature calibration is enabled, the autopilot uses this value to "cancel out" the temperature-induced pressure changes, resulting in a much more stable altitude estimate during long flights or in varying weather conditions.

## The Mathematics
The correction applied to the raw pressure ($P_{raw}$) is a power function based on the temperature difference from a reference point ($T_{zero}$, typically 20°C):

$$ P_{corrected} = P_{raw} + \text{max}(T - T_{zero}, 0)^{BARO\_EXP} $$

This model is chosen for its robustness and its ability to accurately fit the physical characteristics of high-drift barometers.

## The Engineer's View
In `AP_TempCalibration.cpp`, this parameter is defined as `_BARO_EXP` (internal name `baro_exponent`). 
*   **Learning Phase:** When `TCAL_ENABLED` is set to **2 (EnableAndLearn)**, the system monitors pressure vs. temperature while the vehicle is sitting still on the ground. It uses a least-squares error minimization approach to find the exponent that best flattens the pressure curve.
*   **Application:** Once learned, the exponent is saved to this parameter. In subsequent flights (with `TCAL_ENABLED=1`), `AP_TempCalibration::apply_calibration()` uses this exponent to provide a real-time `p_correction` to the `AP_Baro` library.

## Tuning & Behavior
*   **Default Value:** 0 (No correction).
*   **How to Set:** Do not set this manually. Instead, set `TCAL_ENABLED=2`, power on your vehicle, and let it sit still while the internal electronics warm up (about 10-15 minutes). The system will automatically calculate and save the optimal `BARO_EXP`.
*   **Range:** Typically between 0.0 and 2.0.
*   **Effect:** A successful calibration will result in the "Baro Altitude" remaining near 0.0m even as the flight controller gets hot.

