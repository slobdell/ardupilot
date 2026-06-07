---
layout: parameter
name: PLND_ALT_MIN
display_name: "PrecLand minimum alt for retry"
description: "Vehicle will continue landing vertically even if target is lost below this height. This prevents dangerous retries when too close to the ground."
default_value: 0.75
range: 0 5
units: "m"
group: PLND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L155
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# PrecLand minimum alt for retry (PLND_ALT_MIN)

## Description
This parameter defines the "Commit Zone" lower boundary for Precision Landing. 

When a vehicle is very close to the ground (e.g., during the final flare or touchdown), it is often dangerous to attempt a "Retry" (climbing back up) if the landing sensor loses the target (which often happens due to dust, ground effect, or camera focal limits). 

If the vehicle is **below** `PLND_ALT_MIN`, it will ignore the fact that it lost the target and simply continue to land vertically. This ensures a safe touchdown rather than an unexpected and potentially unstable climb-out at very low altitude.

## The Mathematics
This parameter acts as a low-altitude safety gate:

$$ \text{InCommitZone} = \text{IF } (Alt_{RangeFinder} < PLND\_ALT\_MIN) $$

If `InCommitZone` is true, the `TargetState` remains `TARGET_FOUND` (or behaves as such for the landing logic) even if the sensor reporting fails.

## The Engineer's View
In `AC_PrecLand::check_if_sensor_in_range()` (`libraries/AC_PrecLand/AC_PrecLand.cpp`):
1.  The code verifies that the rangefinder altitude is valid.
2.  If `rangefinder_alt_m < _sensor_min_alt`, it returns `false`, preventing the transition to a "Lost" state that would trigger a retry.
3.  This is a robust way to handle the "Blind Spot" that many optical and IR sensors have when they get within a few dozen centimeters of the target.

## Tuning & Behavior
*   **Default Value:** 0.75 meters.
*   **Tall Gear:** If your aircraft has very tall landing gear or a underslung camera, you may need to increase this slightly (e.g., 1.0m).
*   **Small Drones:** Can often leave this at the default or slightly lower.
*   **0:** Disables the minimum altitude check; the vehicle may attempt to retry even a few centimeters from the ground. **Not recommended.**
