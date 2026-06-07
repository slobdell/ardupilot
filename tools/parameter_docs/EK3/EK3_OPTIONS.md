---
layout: parameter
name: EK3_OPTIONS
display_name: EKF3 Options
description: Bitmask of advanced EKF3 options.
default_value: 0
range: 0 1024
units: 
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Options (EK3_OPTIONS)

## Description
`EK3_OPTIONS` is a "Power User" menu for the estimator.

*   **Bit 0:** Enable "Tilt Alignment" during movement.
*   **Bit 1:** Disable GPS glitch protection.
*   **Bit 2:** Enable high-accuracy gyro bias learning.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Leave at **0** unless you have a specific reason to change it (e.g., debugging a compass issue).