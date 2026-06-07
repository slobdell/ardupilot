---
layout: parameter
name: MOT_SPOOL_TIME
display_name: Motor Spool-Up Time
description: The time (in seconds) the motors take to ramp up from zero to minimum throttle.
default_value: 0.5
range: 0.05 2.0
units: s
group: MOT
visual_asset_id: mot_spool_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L172
---

# Motor Spool-Up Time (MOT_SPOOL_TIME)

## Description
`MOT_SPOOL_TIME` defines how "Soft" the initial motor start is. 

When you arm the drone or first apply throttle, ArduPilot doesn't just "slam" the motors to speed. Instead, it ramps the power up gradually over this many seconds. This prevents sudden torque spikes that could flip a drone on the ground or put unnecessary stress on the propellers and frame.

*   **Standard Setting:** 0.5 seconds.
*   **Large Props:** May need 1.0s or more to ensure a smooth, synchronized start without stalling.

## Tuning & Behavior
*   **Default:** 0.5.
*   **Recommendation:** If your drone "hops" or feels nervous the moment it arms, increase this value.
*   **Note:** This parameter also affects the internal state machine that transitions the drone from "On the ground" to "In flight" logic.