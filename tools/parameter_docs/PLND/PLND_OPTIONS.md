---
layout: parameter
name: PLND_OPTIONS
display_name: "Precision Landing Extra Options"
description: "Bitmask for advanced precision landing behaviors, including moving target support."
default_value: 0
range: null
units: "Bitmask"
group: PLND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L170
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Precision Landing Extra Options (PLND_OPTIONS)

## Description
This parameter is a bitmask that enables specific advanced features for the Precision Landing sub-system. It allows the pilot to customize how the vehicle handles dynamic landing scenarios, such as landing on a moving deck or responding to pilot interventions.

## The Mathematics
The bits are processed as individual boolean flags:

*   **Bit 0 (Value 1): Moving Landing Target.** 
    Enables velocity estimation for the target. If the landing sensor detects the target is moving relative to the ground, the autopilot will attempt to match its speed for a more accurate touchdown.
*   **Bit 1 (Value 2): Allow Precision Landing after manual reposition.**
    Normally, if a pilot nudges the sticks during an autonomous landing, precision landing might be disabled. Setting this bit allows the autopilot to resume tracking the target even after the pilot has manually moved the vehicle.
*   **Bit 2 (Value 4): Maintain high speed in final descent.**
    Prevents the vehicle from slowing down to a very cautious descent rate as it nears the target, which is often required for landing on moving ships where "sticking the landing" quickly is safer than hovering close to a moving deck.

## The Engineer's View
In `AC_PrecLand.cpp`, this maps to the `_options` member.
*   **Moving Target Logic:** Checked in `AC_PrecLand::get_target_velocity()`. If bit 0 is not set, the target velocity is always assumed to be zero, which simplifies the Kalman filter state transitions.
*   **Manual Reposition:** This bit is typically checked in the vehicle-specific `mode_land.cpp`.
*   **High Speed Descent:** Affects the velocity constraints in the final stages of the land mission.

## Tuning & Behavior
*   **Bit 0 (1):** **Highly Recommended** if landing on a boat or a moving ground vehicle. Requires an EKF-based estimator (`PLND_EST_TYPE=1`).
*   **Bit 1 (2):** Useful for search-and-rescue or research missions where a pilot might want to move the drone slightly but still use the automated target centering.
*   **Bit 2 (4):** Use with caution. Only recommended for expert users landing on highly dynamic platforms.
