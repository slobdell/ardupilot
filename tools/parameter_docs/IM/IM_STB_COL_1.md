---
layout: parameter
title: IM_STB_COL_1
name: Stabilize Collective Low
group: IM
---

# IM_STB_COL_1: Stabilize Collective Low

## Description
Helicopter's minimum collective pitch setting at zero collective stick input in Stabilize mode. Set this as a percent of collective range given by `H_COL_MAX` minus `H_COL_MIN`.

## Values
- **Range:** 0 to 100
- **Units:** %
- **Increment:** 1
- **Default:** 0

## Description
This parameter defines the bottom point of the collective pitch curve used in **Stabilize** mode.

- **Input:** 0% (Stick fully down).
- **Output:** The value of `IM_STB_COL_1` (as a percentage of the total collective range defined by `H_COL_MIN` and `H_COL_MAX`).
- **Usage:** Typically set to 0% for normal setups, or higher if you want to limit negative pitch (descent rate) in Stabilize mode to prevent accidental rapid descents by beginners.

## Source Code
[ardupilot/libraries/AC_InputManager/AC_InputManager_Heli.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_InputManager/AC_InputManager_Heli.cpp#L29)

