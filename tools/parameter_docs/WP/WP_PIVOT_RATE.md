---
layout: parameter
name: WP_PIVOT_RATE
display_name: Pivot Turn Max Rate
description: The maximum rotation speed (in deg/s) during a pivot turn.
default_value: 60
range: 1 360
units: deg/s
group: WP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AR_WPNav/AR_PivotTurn.cpp#L48
---

# Pivot Turn Max Rate (WP_PIVOT_RATE)

## Description
`WP_PIVOT_RATE` sets the "Spin Speed" for on-the-spot turns.

This is the target angular velocity the rover attempts to maintain while it is performing a pivot turn (stopped in one place).

## Tuning & Behavior
*   **Default:** 60 deg/s.
*   **Recommendation:** If your rover spins too violently and slips its treads/wheels, decrease this to **30 or 40**. If the turn feels sluggish, increase it.