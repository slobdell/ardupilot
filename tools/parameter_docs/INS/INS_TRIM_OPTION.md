---
layout: parameter
name: INS_TRIM_OPTION
display_name: Accel cal trim option
description: Configures how the accelerometer calibration calculates the trim.
default_value: 1
range: 0 2
units: 
group: INS
visual_asset_id: ins_trim_option_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L449
---

# Accel cal trim option (INS_TRIM_OPTION)

## Description
`INS_TRIM_OPTION` determines how ArduPilot calculates the AHRS Trim (Level Horizon) during the Accelerometer Calibration.

*   **0: Don't adjust trims.** The calibration only calculates scaling/offsets for the sensor. The trim (level) remains unchanged.
*   **1: Assume first orientation was level (Default).** The vehicle is assumed to be perfectly level when you start the calibration.
*   **2: Assume ACC_BODYFIX is aligned.** Assumes the flight controller is perfectly aligned with the frame, and calculating trims is unnecessary.

## The Mathematics
The calibration solves for offsets $\vec{b}$ and scale factors $S$.
$$ \vec{a}_{cal} = S (\vec{a}_{raw} - \vec{b}) $$
Then, it calculates the rotation matrix $R_{trim}$ required to make the first sample match the gravity vector $\vec{g} = [0, 0, 1]^T$.

## The Engineer's View
Used in `AP_InertialSensor::_calculate_trim()`.
If set to **1**, the "Level" step is implicitly done as part of the 6-point calibration.
If set to **0**, you must run a separate "Calibrate Level" command after the 6-point calibration.

## Tuning & Behavior
*   **Default Value:** 1
*   **Recommendation:** Leave at **1** for most users. Just ensure the drone is level when you click "Calibrate Accelerometers".