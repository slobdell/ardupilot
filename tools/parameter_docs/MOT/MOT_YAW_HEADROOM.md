---
layout: parameter
name: MOT_YAW_HEADROOM
display_name: Matrix Yaw Min
description: The minimum amount of throttle (PWM range) reserved exclusively for yaw control.
default_value: 200
range: 0 500
units: PWM
group: MOT
visual_asset_id: mot_yaw_headroom_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L32
---

# Matrix Yaw Min (MOT_YAW_HEADROOM)

## Description
`MOT_YAW_HEADROOM` ensures you can always steer, even at full throttle.

When you punch the throttle to 100%, the motors are maxed out. If you try to yaw (spin) at that moment, the drone normally couldn't do it because it can't speed up the motors any further. This parameter forces the average throttle down slightly to keep a "reserve" for yaw.

## Tuning & Behavior
*   **Default Value:** 200 (approx 20% of range).
*   **Recommendation:** Leave at **200**.
*   **Race Quads:** You might reduce this to **50 or 100** to get more raw climb power, at the cost of yaw authority during punch-outs.