---
layout: parameter
name: EK3_NOAID_M_NSE
display_name: EKF3 No-Aid Measurement Noise
description: The expected noise (in m/s) of the velocity estimate when no external aiding (GPS/Flow) is available.
default_value: 10.0
range: 1.0 50.0
units: m/s
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 No-Aid Measurement Noise (EK3_NOAID_M_NSE)

## Description
`EK3_NOAID_M_NSE` prevents the EKF from exploding when GPS is lost.

When all position sensors fail, the EKF assumes the drone is stationary (or moving at constant velocity) with a very high uncertainty. This parameter sets that uncertainty.

## Tuning & Behavior
*   **Default Value:** 10.0 m/s.