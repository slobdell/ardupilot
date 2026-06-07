---
layout: parameter
name: ACRO_YAW_P
display_name: Acro Mode Yaw Gain
description: Converts pilot yaw stick input into a target rotation rate in Acro mode.
default_value: 4.5
range: 1.0 10.0
units: 
group: ACRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Acro Mode Yaw Gain (ACRO_YAW_P)

## Description
`ACRO_YAW_P` defines the "Sensitivity" of the yaw stick while flying in **Acro** mode.

In Acro mode, your sticks do not control the drone's angle; they control its *rate of rotation*. This parameter sets the multiplier for that command. A higher value means the drone will spin faster for the same amount of stick movement.

## Tuning & Behavior
*   **Default:** 4.5.
*   **Effect of Increasing:** The drone feels "faster" and more responsive on the yaw axis.
*   **Recommendation:** If you find the drone rotates too fast to control precisely during stunts, decrease this value to **3.0 or 2.0**.