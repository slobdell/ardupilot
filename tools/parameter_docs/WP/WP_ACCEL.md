---
layout: parameter
name: WP_ACCEL
display_name: Waypoint Acceleration
description: The maximum acceleration used for autonomous waypoint navigation.
default_value: 0
range: 0 100
units: m/s/s
group: WP
visual_asset_id: waypoint_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AR_WPNav/AR_WPNav.cpp#L76
---

# Waypoint Acceleration (WP_ACCEL)

## Description
`WP_ACCEL` determines how aggressively the vehicle speeds up and slows down during an autonomous mission.

*   **Higher Value:** Faster acceleration and more "snappy" starts/stops.
*   **Lower Value:** Smoother, more gradual transitions.

## Tuning & Behavior
*   **Default:** 0.
*   **Fallback:** If set to 0, the autopilot uses the value from the attitude controller (`ATC_ACCEL_MAX`).
*   **Recommendation:** Use **2.0** to **5.0** for a smooth but responsive Rover.