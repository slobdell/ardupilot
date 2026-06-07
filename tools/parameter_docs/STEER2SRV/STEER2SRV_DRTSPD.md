---
layout: parameter
name: STEER2SRV_DRTSPD
display_name: Ground Steering Derating Start Speed
description: The ground speed (in m/s) above which steering authority begins to be reduced.
default_value: 0
range: 0 50
units: m/s
group: STEER2SRV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AP_SteerController.cpp#L100
---

# Ground Steering Derating Start Speed (STEER2SRV_DRTSPD)

## Description
`STEER2SRV_DRTSPD` defines the speed at which the autopilot begins to apply the "Speed-Based Numbing" for ground steering.

Below this speed, you have 100% steering authority. Above this speed, the authority is reduced based on [STEER2SRV_DRTFCT](STEER2SRV_DRTFCT.html).

## Tuning & Behavior
*   **Default:** 0 (Derating starts immediately from 0 speed).
*   **Recommendation:** Set to your typical "Slow Taxi" speed (e.g. **2.0 or 3.0 m/s**). This ensures you have full control for parking but automatic protection as soon as you start your takeoff run.