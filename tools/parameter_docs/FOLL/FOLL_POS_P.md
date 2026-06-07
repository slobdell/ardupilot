---
layout: parameter
name: FOLL_POS_P
display_name: "Follow position error P gain"
description: "The Proportional gain for the Follow Mode position controller. Converts position error into velocity/acceleration demand."
default_value: 0.1
range: 0.01 1.0
units: "Gain"
group: FOLL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Follow/AP_Follow.cpp#L125
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Follow position error P gain (FOLL_POS_P)

## Description
This parameter tunes the aggressiveness of the drone when chasing a moving target. It is the Proportional gain of the position controller used specifically in Follow mode.

If the drone falls behind the target, this gain determines how hard it accelerates to catch up.
*   **High P:** The drone reacts instantly to target movement but may twitch or overshoot if the target stops suddenly.
*   **Low P:** The drone reacts smoothly but may lag behind the target, effectively "rubber-banding" as the distance increases.

## The Mathematics
The controller calculates the position error ($E_{pos}$) between the drone and the target (plus offsets). The desired velocity adjustment is proportional to this error:

$$ V_{correction} = FOLL\_POS\_P \times E_{pos} $$

This velocity demand is then passed to the vehicle's standard velocity controller (which has its own PIDs).

## The Engineer's View
In `AP_Follow.cpp`, this is defined as `_p_pos`.
The Follow library does not control the motors directly. Instead, it calculates a 3D target position and feeds it into the vehicle's position controller (e.g., `AC_PosControl` for Copters). This P-gain works "upstream" of the main flight controller PIDs, shaping the demand signal.

## Tuning & Behavior
*   **Default Value:** 0.1.
*   **Range:** 0.01 to 1.0.
*   **Recommendation:** Start with the default. If the drone lags too far behind a fast-moving target, increase by 0.05 increments.
*   **Overshoot:** If the drone flies past the target when the target stops, decrease this value.

