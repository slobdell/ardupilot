---
layout: parameter
name: ATC_STR_RAT_MAX
display_name: Steering Control Rotation Rate Maximum
description: The maximum rotation rate (in degrees per second) the rover is allowed to command during steering.
default_value: 120
range: 0 1000
units: deg/s
group: ATC
visual_asset_id: atc_str_rat_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.cpp#L198
---

# Steering Control Rotation Rate Maximum (ATC_STR_RAT_MAX)

## Description
`ATC_STR_RAT_MAX` limits how fast your rover turns.

It acts as a speed governor for the yaw axis. Even if the navigation controller demands a sharp 90-degree turn, the steering controller will not command a rotation rate higher than this value.

*   **Low Value (e.g. 60):** The rover turns slowly and gracefully. Good for large, top-heavy vehicles to prevent rollovers.
*   **High Value (e.g. 360):** The rover turns instantly. Good for small, skid-steering bots.

## The Mathematics
The desired turn rate $\omega_{target}$ is constrained:
$$ \omega_{target} = \text{constrain}(\omega_{requested}, -\text{ATC\_STR\_RAT\_MAX}, \text{ATC\_STR\_RAT\_MAX}) $$

## The Engineer's View
Defined in `AR_AttitudeControl.cpp`.
Used in `get_steering_out_rate()`.
This limit is applied *after* the lateral acceleration limit (`ATC_TURN_MAX_G`). If the G-force limit allows a turn rate of 200 deg/s, but `ATC_STR_RAT_MAX` is 100 deg/s, the turn rate will be capped at 100 deg/s.

## Tuning & Behavior
*   **Default Value:** 120 deg/s.
*   **Recommendation:**
    *   **Ackermann Steering (Car):** Set to match the physical turning circle speed (usually 60-90 deg/s).
    *   **Skid Steering (Tank):** Set to 180-360 deg/s for snappy pivots.