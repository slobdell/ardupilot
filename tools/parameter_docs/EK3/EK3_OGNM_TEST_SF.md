---
layout: parameter
name: EK3_OGNM_TEST_SF
display_name: EKF3 On-Ground Movement Test Scale
description: A scaling factor for the on-ground movement check.
default_value: 1.0
range: 1.0 10.0
units: 
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 On-Ground Movement Test Scale (EK3_OGNM_TEST_SF)

## Description
`EK3_OGNM_TEST_SF` helps the EKF decide if it is flying.

The EKF assumes the drone is stationary on the ground. If the gyro/accel indicates movement that exceeds a threshold, the EKF switches to "In Air" mode. This parameter scales that threshold.

## Tuning & Behavior
*   **Default Value:** 1.0.
*   **Recommendation:** Increase if you are launching from a moving boat or vehicle.