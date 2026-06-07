---
layout: parameter
name: VISO_POS_M_NSE
display_name: Visual Odometry Position Noise
description: The minimum expected position noise (uncertainty) for the vision sensor.
default_value: 0.2
range: 0.1 10.0
units: m
group: VISO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_VisualOdom/AP_VisualOdom.cpp#L99
---

# Visual Odometry Position Noise (VISO_POS_M_NSE)

## Description
`VISO_POS_M_NSE` tells the EKF how much to "Trust" the position data from your vision sensor.

If the vision sensor reports a noise value that is lower than this parameter, the autopilot overrides it with this value. This ensures the navigation filter remains conservative and doesn't over-react to potentially over-confident vision data, preventing the drone from "twitching" in high-gain vision scenarios.

## Tuning & Behavior
*   **Default:** 0.2 m.
*   **Recommendation:** Leave at **0.2** for standard Intel T265 setups.