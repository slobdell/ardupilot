---
layout: parameter
name: ATC_BAL_LIM_THR
display_name: Pitch control limit throttle threshold
description: The throttle percentage (0.0 to 1.0) above which the pitch limit starts to be restricted to prevent a balance bot from falling.
default_value: 0.6
range: 0.0 1.0
units: 
group: ATC
visual_asset_id: atc_bal_lim_tc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.cpp#L435
---

# Pitch control limit throttle threshold (ATC_BAL_LIM_THR)

## Description
`ATC_BAL_LIM_THR` sets the "Power Safety Line" for balancing robots.

If the motors are using more than 60% (0.6) of their power just to maintain speed, they have very little "headroom" left to fix a balance error. This parameter tells the autopilot at what point it should start worrying and limit how far the robot is allowed to tilt.

## Tuning & Behavior
*   **Default Value:** 0.6 (60% throttle).
*   **Recommendation:** If you have high-torque motors, you can increase this to **0.8**. If your motors are weak, decrease to **0.4**.