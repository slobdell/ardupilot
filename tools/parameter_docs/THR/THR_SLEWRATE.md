---
layout: parameter
name: THR_SLEWRATE
display_name: Throttle Slew Rate
description: The maximum rate (in percentage per second) at which the throttle signal can change.
default_value: 100
range: 0 500
units: %/s
group: THR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp#L107
---

# Throttle Slew Rate (THR_SLEWRATE)

## Description
`THR_SLEWRATE` prevents the autopilot from "slamming" the throttle.

If you are using a large gas engine or a high-torque helicopter motor, changing from 0% to 100% throttle instantly can cause mechanical failure or strip gears. This parameter forces the throttle to ramp up or down smoothly over a specific time.

*   **100:** Allows the throttle to move from 0% to 100% in exactly one second.
*   **0:** Unlimited (Instant response).

## Tuning & Behavior
*   **Default:** 100 (Heli) or 0 (Multicopter).
*   **Recommendation:** For large electric motors or combustion engines, set to **50 or 100** to ensure a smooth power transition.
*   **Note:** This is separate from the `MOT_SPOOL_TIME` which only applies at the moment of arming. `THR_SLEWRATE` applies throughout the entire flight.