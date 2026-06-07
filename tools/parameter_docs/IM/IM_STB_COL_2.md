---
layout: parameter
title: IM_STB_COL_2
name: Stabilize Collective Mid-Low
group: IM
---

# IM_STB_COL_2: Stabilize Collective Mid-Low

## Description
Helicopter's collective pitch setting at mid-low (40%) collective stick input in Stabilize mode. Set this as a percent of collective range given by `H_COL_MAX` minus `H_COL_MIN`.

## Values
- **Range:** 0 to 100
- **Units:** %
- **Increment:** 1
- **Default:** 40

## Description
This parameter defines the second point of the collective pitch curve used in **Stabilize** mode.

- **Input:** 40% (Stick slightly below center).
- **Output:** The value of `IM_STB_COL_2` (as a percentage of the total collective range).
- **Usage:** Typically set to a value that provides a gentle descent or hover-capable pitch, depending on pilot preference. This helps define the transition from minimum pitch to hover pitch.

## Source Code
[ardupilot/libraries/AC_InputManager/AC_InputManager_Heli.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_InputManager/AC_InputManager_Heli.cpp#L38)

