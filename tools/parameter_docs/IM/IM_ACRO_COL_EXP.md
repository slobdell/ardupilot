---
layout: parameter
title: IM_ACRO_COL_EXP
name: Acro Mode Collective Expo
group: IM
---

# IM_ACRO_COL_EXP: Acro Mode Collective Expo

## Description
Used to soften collective pitch inputs near center point in Acro mode.

## Values
- **Range:** 0 to 1.0
- **Default:** 0
- **Increment:** 0.1

| Value | Meaning |
| :--- | :--- |
| 0 | Disabled (Linear) |
| 0.1 | Very Low |
| 0.2 | Low |
| 0.3 | Medium |
| 0.4 | High |
| 0.5 | Very High |

## Description
This parameter adds "Expo" (Exponential curvature) to the collective pitch stick when flying in Acro mode.

- **Effect:** It reduces the sensitivity of the collective stick around the center position (mid-stick).
- **Purpose:** Allows for more precise control of blade pitch near 0 degrees (typically mid-stick in Acro setup) while still allowing full positive and negative pitch at the stick extremes. This is useful for 3D flight maneuvers where precise management of zero-lift is required.

## Source Code
[ardupilot/libraries/AC_InputManager/AC_InputManager_Heli.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_InputManager/AC_InputManager_Heli.cpp#L20)

