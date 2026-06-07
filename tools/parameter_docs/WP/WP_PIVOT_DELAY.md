---
layout: parameter
name: WP_PIVOT_DELAY
display_name: Pivot Turn Pause Delay
description: The time (in seconds) to wait after a pivot turn before resuming forward movement.
default_value: 0
range: 0 60
units: s
group: WP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AR_WPNav/AR_PivotTurn.cpp#L60
---

# Pivot Turn Pause Delay (WP_PIVOT_DELAY)

## Description
`WP_PIVOT_DELAY` introduces a brief "Rest" after a Rover or Boat spins on the spot.

Pivot turns can be aggressive and cause the vehicle to shake or the GPS heading to become slightly noisy. This delay allows the mechanical momentum to dissipate and the navigation filters to settle before the vehicle applies forward power.

## Tuning & Behavior
*   **Default:** 0 seconds (No delay).
*   **Recommendation:** Use **0.5 or 1.0 seconds** if your rover tends to "wobble" or depart from the track immediately after finishing a pivot turn.