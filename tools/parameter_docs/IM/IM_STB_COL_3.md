---
layout: parameter
title: IM_STB_COL_3
name: Stabilize Collective Mid-High
group: IM
---

# IM_STB_COL_3: Stabilize Collective Mid-High

## Description
Helicopter's collective pitch setting at mid-high (60%) collective stick input in Stabilize mode. Set this as a percent of collective range given by `H_COL_MAX` minus `H_COL_MIN`.

## Values
- **Range:** 0 to 100
- **Units:** %
- **Increment:** 1
- **Default:** 60

## Description
This parameter defines the third point of the collective pitch curve used in **Stabilize** mode.

- **Input:** 60% (Stick slightly above center).
- **Output:** The value of `IM_STB_COL_3` (as a percentage of the total collective range).
- **Usage:** Typically set to a value that provides a hover or gentle climb. This, along with `IM_STB_COL_2`, creates the "hover band" sensitivity.

## Source Code
[ardupilot/libraries/AC_InputManager/AC_InputManager_Heli.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_InputManager/AC_InputManager_Heli.cpp#L47)

