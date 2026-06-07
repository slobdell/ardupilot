---
layout: parameter
name: EK3_VIS_VERR_MAX
display_name: EKF3 Visual Odometry Max Error
description: The maximum velocity error (in m/s) assumed for visual odometry measurements when quality is low.
default_value: 0.9
range: 0.5 5.0
units: m/s
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Visual Odometry Max Error (EK3_VIS_VERR_MAX)

## Description
`EK3_VIS_VERR_MAX` defines the trust floor for Visual Odometry.

When the VO system reports poor quality (e.g., dark room, featureless wall), the EKF uses this error value.

## Tuning & Behavior
*   **Default Value:** 0.9 m/s.