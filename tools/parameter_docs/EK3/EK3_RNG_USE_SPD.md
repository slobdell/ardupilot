---
layout: parameter
name: EK3_RNG_USE_SPD
display_name: EKF3 Rangefinder Use Speed
description: The maximum ground speed (in m/s) at which the rangefinder can be used as the primary height source.
default_value: 2.0
range: 2.0 6.0
units: m/s
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Rangefinder Use Speed (EK3_RNG_USE_SPD)

## Description
`EK3_RNG_USE_SPD` prevents using Lidar altitude when flying fast.

Many Lidars struggle when the ground is rushing by (motion blur) or when the drone is pitched over (measuring diagonal distance instead of vertical). This parameter forces a switch back to Baro/GPS if the drone exceeds this speed.

## Tuning & Behavior
*   **Default Value:** 2.0 m/s.
*   **Recommendation:** Keep low (2-6 m/s) to ensure Lidar is only used for takeoff/landing hover.