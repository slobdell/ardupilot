---
layout: parameter
name: VIB_FREQ
display_name: Vibration Frequencies
description: Vibration frequencies on each axis (SITL only).
default_value: 0
range: 0 1000
units: Hz
group: VIB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L331
---

# VIB_FREQ: Vibration Frequencies

## Description
Vibration frequencies on each axis.

## Values
- **Range:** 0 to 1000
- **Units:** Hz
- **Default:** 0

## Description
This parameter injects simulated vibration noise into the SITL (Software In The Loop) physics engine.

- **Function:** It sets the base frequency of the vibration.
- **Components:** This is a Vector3f parameter (X, Y, Z). You can set different frequencies for each axis.
- **Usage:** Used by developers to test how well the autopilot's filters (`INS_GYRO_FILTER`, `INS_ACCEL_FILTER`) handle noise.
