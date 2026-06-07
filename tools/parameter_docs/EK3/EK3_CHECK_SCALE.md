---
layout: parameter
name: EK3_CHECK_SCALE
display_name: EKF3 Consistency Check Scale
description: A scaling factor for the EKF health and consistency checks.
default_value: 100
range: 50 200
units: '%'
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Consistency Check Scale (EK3_CHECK_SCALE)

## Description
`EK3_CHECK_SCALE` is the "Sensitivity Knob" for the EKF failsafe system.

It scales the thresholds used to determine if the IMUs, Compass, and GPS are healthy. If you have a very high-vibration airframe that constantly triggers false "EKF Variance" warnings, you can increase this to make the autopilot more "Relaxed."

## Tuning & Behavior
*   **Default Value:** 100 (100%).
*   **Increased (e.g., 150):** Autopilot becomes more tolerant of noise and small sensor errors. Safer for noisy airframes but slower to detect actual sensor failures.
*   **Decreased (e.g., 80):** Autopilot becomes "Paranoid." It will detect failures faster but is more likely to trigger false failsafes in gusty wind.