---
layout: parameter
name: FOLL_JERK_D
display_name: "Follow Vertical Jerk Limit"
description: "Jerk limit for the vertical kinematic input shaping. Controls the rate of change of vertical acceleration."
default_value: 0
range: 0 50
units: "m/s/s/s"
group: FOLL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Follow/AP_Follow.cpp#L170
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Follow Vertical Jerk Limit (FOLL_JERK_D)

## Description
This parameter limits the "Jerk" (rate of change of acceleration) for vertical movements in Follow mode. It is part of the kinematic input shaper, which smooths out the target's movements before they are passed to the flight controller.

A lower jerk limit makes the drone's altitude changes feel smoother and more "organic," reducing mechanical stress and camera shake. A higher limit allows the drone to react more violently to sudden altitude changes by the target.

## The Mathematics
The input shaper limits the third derivative of position ($Z$):

$$ |\frac{d^3Z}{dt^3}| \le FOLL\_JERK\_D $$

This effectively puts a "ramp" on the acceleration command. Instead of instantly demanding 2G climb, the system ramps up to that acceleration over a period defined by this limit.

## The Engineer's View
In `AP_Follow`, this parameter is passed to the `AC_InputManager` or similar kinematic shaping libraries used by the vehicle's position controller. 
*   **0:** Disabled. The system uses the vehicle's default maximum jerk limits (e.g., `PILOT_JERK`).
*   **Non-Zero:** Overrides the default jerk limit specifically for Follow mode operations.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled/Use Vehicle Defaults).
*   **Filming:** Set to a low value (e.g., 5 m/s/s/s) for ultra-smooth cinematic following.
*   **Racing/Tracking:** Set higher or leave at 0 for maximum responsiveness.
