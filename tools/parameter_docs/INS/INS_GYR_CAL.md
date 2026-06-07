---
layout: parameter
name: INS_GYR_CAL
display_name: Gyro Calibration scheme
description: Controls when the automatic gyroscope calibration is performed.
default_value: 1
range: 0 1
units: 
group: INS
visual_asset_id: ins_gyro_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L442
---

# Gyro Calibration scheme (INS_GYR_CAL)

## Description
`INS_GYR_CAL` determines if the autopilot should re-calibrate the gyroscope offsets every time it boots.

*   **0: Never.** Relies on saved offsets. Fast boot, but risky if temperature changes significantly.
*   **1: Start-up only (Default).** Calibrates every time you plug in the battery. Requires the drone to be **still** during startup.

## The Mathematics
The calibration routine calculates the mean value of the gyro output while the vehicle is stationary (assumed 0 rotation) and subtracts this as a bias.
$$ \vec{\omega}_{cal} = \vec{\omega}_{raw} - \vec{\omega}_{bias} $$

## The Engineer's View
If set to **1**, `AP_InertialSensor::init()` calls `_init_gyro()` which blocks startup until the gyros are stable. This is why you see "Calibrating IMU..." on the HUD.
If set to **0**, it skips this and uses the `INS_GYR_OFFS` parameters stored in EEPROM.

## Tuning & Behavior
*   **Default Value:** 1
*   **Recommendation:** Leave at **1**.
*   **Boat Mode:** If launching from a moving boat, you **must** set this to **0** (Never), otherwise the calibration will fail or learn a huge bias (thinking the boat's motion is "still"), causing the drone to flip on takeoff. You must perform a good calibration on land first.