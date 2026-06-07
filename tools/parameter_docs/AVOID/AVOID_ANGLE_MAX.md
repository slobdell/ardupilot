---
layout: parameter
name: AVOID_ANGLE_MAX
display_name: Avoidance Max Lean Angle
description: The maximum lean angle (in centi-degrees) the vehicle will use to avoid an obstacle.
default_value: 1000
range: 0 4500
units: cdeg
group: AVOID
visual_asset_id: avoid_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AC_Avoid.cpp#L85
---

# Avoidance Max Lean Angle (AVOID_ANGLE_MAX)

## Description
`AVOID_ANGLE_MAX` limits how aggressively the drone can tilt away from a threat.

*   **1000 (Default):** 10 degrees. Gentle avoidance.
*   **3000:** 30 degrees. Aggressive dodge.

## Tuning & Behavior
*   **Default Value:** 1000 (10°).
*   **Recommendation:** Keep low (10-15°) to ensure smooth video and prevent the drone from over-reacting to sensor noise.