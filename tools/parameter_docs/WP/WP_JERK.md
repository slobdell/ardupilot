---
layout: parameter
name: WP_JERK
display_name: Waypoint Navigation Jerk Limit
description: Controls the rate of change of acceleration for smooth S-curve waypoint navigation.
default_value: 0
range: 0 100
units: m/s^3
group: WP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AR_WPNav/AR_WPNav.cpp#L85
---

# Waypoint Navigation Jerk Limit (WP_JERK)

## Description
`WP_JERK` defines the "Smoothness" of your drone's speed changes during autonomous missions.

ArduPilot uses **S-curve** path planning to move between waypoints. Unlike older "step" changes in speed, S-curves ramp acceleration up and down gradually. This parameter sets the limit for that ramp (the derivative of acceleration).

*   **Higher Value:** Faster, snappier acceleration and braking.
*   **Lower Value:** More "graceful," cinematographic movements.
*   **0:** (Default). The autopilot sets the jerk limit to match the maximum acceleration ([WP_ACCEL](WP_ACCEL.html)).

## Tuning & Behavior
*   **Recommendation:** Leave at **0** for most applications. 
*   **Usage:** For heavy lifting or filming drones, you can set this to a lower value (e.g. 1.0 or 2.0) to prevent sudden jerks that could cause gimbal vibration or payload swinging.