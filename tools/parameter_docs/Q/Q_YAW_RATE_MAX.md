---
layout: parameter
name: Q_YAW_RATE_MAX
display_name: Maximum Yaw Rate
description: The maximum yaw rate (in degrees per second) allowed in VTOL modes.
default_value: 90
range: 10 360
units: deg/s
group: Q
visual_asset_id: vtol_control_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Maximum Yaw Rate (Q_YAW_RATE_MAX)

## Description
`Q_YAW_RATE_MAX` sets the "Spin Speed" limit.

It determines how fast the drone will rotate when you push the yaw stick to the full deflection.

## Tuning & Behavior
*   **Default Value:** 90 deg/s.
*   **High Value (180+):** Very fast rotation. Good for agile maneuvers but can cause EKF issues if the compass cannot keep up.
*   **Low Value (45):** Slow, scale-like rotation.
*   **Recommendation:** 90 deg/s is a safe and standard limit.