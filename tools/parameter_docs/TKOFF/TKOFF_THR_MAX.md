---
layout: parameter
name: TKOFF_THR_MAX
display_name: Maximum Throttle for Takeoff
description: The maximum throttle setting allowed during an automatic takeoff.
default_value: 0
range: 0 100
units: %
group: TKOFF
visual_asset_id: takeoff_sequence_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L1233
---

# Maximum Throttle for Takeoff (TKOFF_THR_MAX)

## Description
`TKOFF_THR_MAX` allows you to give your plane an "Extra Boost" for the launch. 

In normal cruise, you might want to limit your throttle to 75% to save battery. However, during a hand-launch or a steep climb-out, you need 100% of the available power to avoid hitting the ground. This parameter lets you set a different power limit specifically for the takeoff phase.

*   **0 (Default):** Use the global `THR_MAX` setting for takeoff as well.
*   **100:** Allow full motor power during takeoff, even if the normal limit is lower.

## The Engineer's View
Used by the **TECS (Total Energy Control System)**. 
During the takeoff flight stage, the `aparm.throttle_max` value is replaced by `g.takeoff_throttle_max` if it is non-zero. This ensures the energy controller has the maximum possible "Energy Add" capability to maintain airspeed and climb angle simultaneously.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set to **100** for all hand-launches to ensure the best possible climb rate.
*   **Constraint:** This value is still subject to your ESC's physical limits and the `MOT_PWM_MAX` settings.