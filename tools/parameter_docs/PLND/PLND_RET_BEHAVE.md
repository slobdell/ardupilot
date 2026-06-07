---
layout: parameter
name: PLND_RET_BEHAVE
display_name: "PrecLand retry behaviour"
description: "Selects the location strategy when a landing retry is triggered."
default_value: 0
range: 0 1
units: "Option"
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

# PrecLand retry behaviour (PLND_RET_BEHAVE)

## Description
This parameter defines the "Targeting Strategy" used during a Precision Landing retry. If the vehicle loses sight of the landing target and `PLND_STRICT` is set to retry, the drone will climb and reposition itself to re-acquire the signal. This parameter tells the drone *where* to go during that climb.

*   **0: Go to Target Location.** The drone moves to the last estimated GPS coordinate of the landing target itself.
*   **1: Go to Last Vehicle Location.** The drone moves back to the GPS coordinate where the vehicle was at the moment it last had a solid lock on the target.

## The Mathematics
Regardless of the strategy chosen, the retry logic adds a hardcoded vertical climb offset ($H_{retry}$) to ensure the sensor has a wider field of view for re-acquisition.

$$ Z_{target} = Z_{last\_valid} - 1.5\text{m} $$
*(Note: In NED coordinates, negative Z is up).*

The horizontal (XY) coordinates are determined by the `PLND_RET_BEHAVE` selection:
*   **Mode 0:** $XY_{retry} = XY_{target\_last\_seen}$
*   **Mode 1:** $XY_{retry} = XY_{vehicle\_at\_last\_seen}$

## The Engineer's View
In `AC_PrecLand_StateMachine::retry_landing()` (`libraries/AC_PrecLand/AC_PrecLand_StateMachine.cpp`):
1.  The code reads the behavior preference.
2.  If set to `GO_TO_TARGET_LOC` (0), it calls `_precland->get_last_detected_landing_pos()`.
3.  If set to `GO_TO_LAST_LOC` (1), it calls `_precland->get_last_vehicle_pos_when_target_detected()`.
4.  The state machine then enters the `RETRYING` status, commanding the position controller to converge on this 3D point. Once the drone is within 0.75m of the goal, it attempts to descend again.

## Tuning & Behavior
*   **0 (Default):** Usually best for stationary targets. If the drone was slightly off-center, it will move directly over the last known pad location.
*   **1:** Better for moving targets (like a boat) or if the landing sensor has a narrow field of view. Moving the drone back to where it *knows* it could see the target is often more reliable than moving to where it *thinks* the target was.

