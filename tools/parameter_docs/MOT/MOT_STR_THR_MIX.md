---
layout: parameter
name: MOT_STR_THR_MIX
display_name: Steering vs Throttle Priority
description: Balances the motor output priority between steering and forward speed for skid-steer rovers.
default_value: 0.5
range: 0.1 1.0
units: 
group: MOT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AR_Motors/AP_MotorsUGV.cpp#L104
---

# Steering vs Throttle Priority (MOT_STR_THR_MIX)

## Description
`MOT_STR_THR_MIX` defines what happens when your Rover is "Maxed Out." 

On a **Skid-Steer** rover (like a tank), the motors are used for both turning and driving forward. If you command full speed AND a hard turn, the autopilot may run out of motor power. This parameter tells the autopilot which one is more important:

*   **Higher Value (0.8 - 1.0):** Prioritizes **Steering**. The rover will slow down to ensure it can make the turn accurately. (Recommended for precise autonomous missions).
*   **Lower Value (0.2 - 0.5):** Prioritizes **Throttle**. The rover will keep its speed up, even if it has to widen the turn. (Recommended for high-speed racing).

## Tuning & Behavior
*   **Default:** 0.5 (Balanced).
*   **Recommendation:** If your rover "Overshoots" corners while trying to maintain speed, increase this value to **0.7** or **0.8**.
*   **Note:** This only applies to vehicles with skid-steering (tank mode) enabled.