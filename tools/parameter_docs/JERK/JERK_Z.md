---
layout: parameter
title: JERK_Z
name: Jerk limit for the vertical kinematic input shaping
group: JERK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L324
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.h#L521
---

# JERK_Z: Jerk limit for the vertical kinematic input shaping

## Description
Jerk limit of the vertical kinematic path generation used to determine how quickly the aircraft varies the acceleration target.

## Values
- **Range:** 5 to 50
- **Units:** m/s/s/s
- **Increment:** 1
- **Default:** 5.0

## Description
This parameter controls the smoothness of vertical (Z-axis) acceleration changes in autonomous modes. It effectively limits how fast the autopilot can change the climb or descent rate command.

- **Lower Value:** Smoother transitions between climbing, holding altitude, and descending. Prevents sudden "jumps" in motor output.
- **Higher Value:** Faster reaction to altitude change requests, but may cause the vehicle to feel "hard" or jerky in altitude changes.

## Source Code
[ardupilot/libraries/AC_AttitudeControl/AC_PosControl.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L324)

