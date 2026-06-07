---
layout: parameter
name: QWIK_YAW_D_MAX
display_name: "Quicktune Yaw D max"
description: "The maximum allowable derivative gain (D) for the yaw axis during automated tuning."
default_value: 0.01
range: 0.001 1.0
units: "Gain"
group: QWIK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Quicktune/AP_Quicktune.cpp#L78
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Quicktune Yaw D max (QWIK_YAW_D_MAX)

## Description
This parameter defines the maximum limit for the Yaw Derivative (D) gain that the Quicktune system is allowed to set. 

The D-gain is primarily used to "dampen" the tail of the aircraft, preventing it from overshooting when you stop a turn. However, yaw dynamics involve a lot of inertia, and setting the D-gain too high can cause high-frequency vibrations that result in hot motors or ESC failures. This parameter ensures that the automated tuning process never enters that dangerous high-gain territory.

## The Mathematics
The system monitors for oscillations while increasing the D-gain, but will stop immediately if the gain reaches this ceiling:

$$ K_{d\_yaw} = \min(K_{target}, QWIK\_YAW\_D\_MAX) $$

A value of **0.01** is a common starting point for medium-sized multirotors.

## The Engineer's View
In `AP_Quicktune::gain_limit()` (`libraries/AP_Quicktune/AP_Quicktune.cpp`):
1.  The code checks the tuning axis.
2.  For the `YAW` axis, it specifically retrieves the `_yaw_d_max` parameter value.
3.  This ceiling is used in the `limited` check within the `update()` function to terminate the "Search" phase for the D-gain stage of the tune.
4.  By providing a hard limit, ArduPilot protects against "false negatives" where the algorithm might not detect a subtle high-frequency vibration that is still damaging to the hardware.

## Tuning & Behavior
*   **Default Value:** 0.01.
*   **Range:** 0.001 to 1.0.
*   **When to Increase:** If your vehicle has very little damping and "bounces" at the end of a yaw rotation after a Quicktune session.
*   **When to Decrease:** If your motors are warm after a flight where you used Quicktune, or if you hear high-frequency "chirping" from the motors during yaw maneuvers.
*   **Note:** Most vehicles require very little Yaw D-gain compared to Roll or Pitch.

