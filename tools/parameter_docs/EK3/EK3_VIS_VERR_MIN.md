---
layout: parameter
name: EK3_VIS_VERR_MIN
display_name: EKF3 Visual Odometry Min Error
description: The minimum velocity error (in m/s) assumed for visual odometry measurements.
default_value: 0.1
range: 0.05 0.5
units: m/s
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Visual Odometry Min Error (EK3_VIS_VERR_MIN)

## Description
`EK3_VIS_VERR_MIN` sets the trust ceiling for Visual Odometry (VO).

VO systems (like Intel RealSense or Zed) report a "Quality" metric. When quality is 100%, the EKF uses this error value.

*   **0.1:** Very confident.
*   **0.5:** Less confident.

## Tuning & Behavior
*   **Default Value:** 0.1 m/s.