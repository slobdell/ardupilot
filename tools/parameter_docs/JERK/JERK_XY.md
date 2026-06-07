---
layout: parameter
title: JERK_XY
name: Jerk limit for the horizontal kinematic input shaping
group: JERK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L315
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.h#L57
---

# JERK_XY: Jerk limit for the horizontal kinematic input shaping

## Description
Jerk limit of the horizontal kinematic path generation used to determine how quickly the aircraft varies the acceleration target.

## Values
- **Range:** 1 to 20
- **Units:** m/s/s/s
- **Increment:** 1
- **Default:** 5.0

## Description
This parameter controls the smoothness of horizontal acceleration changes in autonomous modes (like Loiter, Auto, Guided). "Jerk" is the rate of change of acceleration.

- **Lower Value (e.g., 2-4):** Acceleration ramps up and down slowly. The vehicle will feel very smooth and fluid but may feel "loose" or slow to react to stick inputs in Loiter.
- **Higher Value (e.g., 10-15):** Acceleration changes rapidly. The vehicle will feel responsive and "snappy" but may be jerky or twitchy if set too high for the physical capabilities of the airframe.

## Source Code
[ardupilot/libraries/AC_AttitudeControl/AC_PosControl.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L315)

