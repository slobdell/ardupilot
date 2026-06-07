---
layout: parameter
title: IM_STB_COL_4
name: Stabilize Collective High
group: IM
---

# IM_STB_COL_4: Stabilize Collective High

## Description
Helicopter's maximum collective pitch setting at full collective stick input in Stabilize mode. Set this as a percent of collective range given by `H_COL_MAX` minus `H_COL_MIN`.

## Values
- **Range:** 0 to 100
- **Units:** %
- **Increment:** 1
- **Default:** 100

## Description
This parameter defines the top point of the collective pitch curve used in **Stabilize** mode.

- **Input:** 100% (Stick fully up).
- **Output:** The value of `IM_STB_COL_4` (as a percentage of the total collective range).
- **Usage:** Typically set to 100% to allow full climb performance, but can be reduced if the pilot wants to limit the maximum climb rate in Stabilize mode.

## Source Code
[ardupilot/libraries/AC_InputManager/AC_InputManager_Heli.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_InputManager/AC_InputManager_Heli.cpp#L56)

