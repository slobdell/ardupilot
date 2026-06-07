---
layout: parameter
name: PLND_ALT_MAX
display_name: "PrecLand maximum alt for retry"
description: "Vehicle will continue landing vertically until this height if target is not found. Below this height, if the target is lost, a landing retry or failsafe is triggered."
default_value: 8.0
range: 0 50
units: "m"
group: PLND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L161
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# PrecLand maximum alt for retry (PLND_ALT_MAX)

## Description
This parameter defines the "Active Search Zone" upper boundary for Precision Landing. 

When the vehicle is descending in a precision landing mode, it expects to see the landing target (e.g., an IR beacon or AprilTag). If the vehicle is above `PLND_ALT_MAX`, it will continue to descend vertically even if it doesn't see the target. Once it drops **below** this altitude, the "Retry Logic" becomes active. If the target is lost while the vehicle is below this height, it will trigger a retry (climb back up to look for it) or a failsafe, depending on `PLND_STRICT`.

## The Mathematics
This parameter acts as a height-based logic gate ($H_{gate}$):

$$ \text{RetryLogicActive} = \text{IF } (Alt_{RangeFinder} < PLND\_ALT\_MAX) $$

It requires a valid downward-facing rangefinder to function. If the rangefinder is not present or unhealthy, this altitude check is bypassed or fails safe depending on `PLND_OPTIONS`.

## The Engineer's View
In `AC_PrecLand::check_if_sensor_in_range()` (`libraries/AC_PrecLand/AC_PrecLand.cpp`):
1.  The code checks if `_sensor_max_alt` is non-zero.
2.  It verifies that the rangefinder altitude is valid.
3.  If `rangefinder_alt_m > _sensor_max_alt`, it returns `false`, meaning the "Retry/Lost" logic should not yet be triggered (the vehicle is too high to reasonably expect a solid lock).
4.  Once below this height, the `TargetState` can transition to `TARGET_RECENTLY_LOST` or `TARGET_OUT_OF_RANGE`.

## Tuning & Behavior
*   **Default Value:** 8 meters.
*   **Agile Aircraft:** Can be set higher (e.g., 15m) if the camera/sensor has a very wide field of view.
*   **Limited Sensors:** Should be set to the maximum reliable range of your landing sensor (e.g., IR-Lock is usually effective up to ~10-15m).
*   **0:** Disables the maximum altitude check; retry logic is always active if the target is lost.

