---
layout: parameter
name: FOLL_ACCEL_D
display_name: "Follow Vertical Acceleration Limit"
description: "Acceleration limit for the vertical kinematic input shaping. Controls the maximum rate of climb/descent change."
default_value: 0
range: 0 50
units: "m/s/s"
group: FOLL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Follow/AP_Follow.cpp#L169
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Follow Vertical Acceleration Limit (FOLL_ACCEL_D)

## Description
This parameter sets the maximum vertical acceleration the drone is allowed to use while tracking a target in Follow mode. 

By limiting the acceleration, you ensure that the drone transitions smoothly between climbing and descending, preventing sudden throttle spikes that could waste battery or destabilize a camera gimbal.

## The Mathematics
The input shaper constrains the second derivative of position ($Z$):

$$ |\frac{d^2Z}{dt^2}| \le FOLL\_ACCEL\_D $$

This acts as a "ceiling" on the throttle demand logic. Even if the target suddenly drops 10 meters, the drone will only accelerate downwards at this specified rate until it reaches its maximum descent speed.

## The Engineer's View
In `AP_Follow`, this parameter is part of the kinematic shaping configuration passed to the position controller.
*   **0:** Disabled. The system uses the vehicle's standard vertical acceleration limits (e.g., `PILOT_ACCEL_Z`).
*   **Non-Zero:** Overrides the default limits specifically for Follow mode. This allows you to have a very aggressive "Sport Mode" for manual flying but a gentle, cinematic behavior for Follow mode.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Range:** 0 to 50 m/s/s.
*   **Smooth Filming:** Set to **1 or 2 m/s/s**.
*   **Aggressive Tracking:** Set to **5+ m/s/s** or leave at 0.
