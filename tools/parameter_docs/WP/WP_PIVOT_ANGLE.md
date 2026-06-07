---
layout: parameter
name: WP_PIVOT_ANGLE
display_name: Pivot Turn Threshold Angle
description: The heading error (in degrees) above which the vehicle will perform a pivot turn (on the spot) instead of a steering turn.
default_value: 60
range: 0 360
units: deg
group: WP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AR_WPNav/AR_PivotTurn.cpp#L42
---

# Pivot Turn Threshold Angle (WP_PIVOT_ANGLE)

## Description
`WP_PIVOT_ANGLE` determines when a Rover or Boat should stop and spin in place rather than trying to make a wide arc turn.

This is only used for **Skid-Steer** (tank-like) vehicles. If the turn required to reach the next waypoint is sharper than this angle, the vehicle will come to a complete halt, spin until its nose points at the target, and then resume driving forward.

*   **0:** Disabled. The vehicle always attempts a wide steering turn.
*   **60 (Default):** Standard for most rovers. 

## Tuning & Behavior
*   **Recommendation:** Set between **45 and 90** degrees. 
*   **Significance:** Prevents the vehicle from making massive, uncontrolled "S-turns" when trying to reach a waypoint that is behind it or at a sharp angle.