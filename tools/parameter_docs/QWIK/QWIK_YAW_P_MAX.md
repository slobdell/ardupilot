---
layout: parameter
name: QWIK_YAW_P_MAX
display_name: "Quicktune Yaw P max"
description: "The maximum allowable proportional gain (P) for the yaw axis during automated tuning."
default_value: 0.5
range: 0.1 3.0
units: "Gain"
group: QWIK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Quicktune/AP_Quicktune.cpp#L71
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Quicktune Yaw P max (QWIK_YAW_P_MAX)

## Description
This parameter sets a "Safety Ceiling" for the Yaw Proportional (P) gain during the Quicktune process. It prevents the automated tuning algorithm from increasing the yaw responsiveness beyond a point that might be physically dangerous or cause mechanical fatigue, even if the software does not detect any oscillations.

Yaw control on many aircraft (especially multirotors) is achieved via motor torque differential, which is less efficient than roll or pitch. Setting a maximum limit ensures that the tune remains conservative and doesn't demand more from the motors than is safe for long-term operation.

## The Mathematics
The tuning algorithm calculates an incremental target gain ($K_{target}$), but the final value applied to the vehicle's PID controller is always capped:

$$ K_{p\_yaw} = \min(K_{target}, QWIK\_YAW\_P\_MAX) $$

This prevents the algorithm from "running away" if the oscillation detection threshold is set too high or if the airframe is exceptionally stiff.

## The Engineer's View
In `AP_Quicktune::gain_limit()` (`libraries/AP_Quicktune/AP_Quicktune.cpp`):
1.  The code checks if the axis being tuned is `AxisName::YAW`.
2.  If true, it returns the value of `yaw_p_max`. 
3.  In the `update()` loop, this limit is used to check if the current test gain has reached the user-defined boundary (`limited = (limit > 0.0 && pval >= limit)`). 
4.  If the limit is hit, the tuning stage for that gain is marked as "Done" and the system moves to the next parameter.

## Tuning & Behavior
*   **Default Value:** 0.5.
*   **Range:** 0.1 to 3.0.
*   **When to Increase:** If the vehicle still feels "lazy" or slow to hold heading after a Quicktune session, and you are certain the mechanics can handle more aggressive torque changes.
*   **When to Decrease:** If you have a very powerful, high-torque vehicle where even small gains result in violent yaw kicks.
*   **Dependencies:** Works in conjunction with `QWIK_Y_PI_RATIO` to determine the final $K_i$ for the yaw axis.

