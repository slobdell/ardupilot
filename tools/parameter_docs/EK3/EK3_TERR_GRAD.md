---
layout: parameter
name: EK3_TERR_GRAD
display_name: EKF3 Terrain Gradient
description: The maximum expected terrain gradient (slope) for the terrain estimator.
default_value: 0.1
range: 0 0.5
units: m/m
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Terrain Gradient (EK3_TERR_GRAD)

## Description
`EK3_TERR_GRAD` tells the EKF how hilly the ground is expected to be.

This is used for Optical Flow and Terrain Following. If the Lidar distance changes rapidly, the EKF uses this parameter to decide if the drone moved up/down or if the ground moved (a hill).

## Tuning & Behavior
*   **Default Value:** 0.1 (10% slope).
*   **Hilly Terrain:** Increase to **0.5** if flying over steep hills.