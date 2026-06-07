---
layout: parameter
title: STILL_THRESH
name: Stillness threshold for detecting if we are moving
group: STILL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L389
---

# STILL_THRESH: Stillness threshold for detecting if we are moving

## Description
Threshold to tolerate vibration to determine if vehicle is motionless.

## Values
- **Range:** 0.05 to 50
- **Default:** 0.1 (Plane/Rover), 2.5 (Copter/Heli)

## Description
This parameter sets the sensitivity of the "Motion Detection" logic used by the EKF (Extended Kalman Filter) and the calibration routines.

- **Function:** The autopilot monitors the accelerometer noise. If the total acceleration variance is below this threshold, it assumes the vehicle is sitting still on the ground.
- **Usage:**
    - **Calibration:** When calibrating the gyros on boot, the vehicle must be "still." If you are on a boat or a windy platform, you may need to **increase** this threshold so the calibration can complete.
    - **Arming:** Some arming checks require the vehicle to be motionless.
- **Tuning:** Increase if you have trouble passing pre-arm checks on a moving platform. Decrease for high-precision calibration on a solid bench.

