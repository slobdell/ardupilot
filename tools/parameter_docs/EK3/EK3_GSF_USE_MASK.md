---
layout: parameter
name: EK3_GSF_USE_MASK
display_name: EKF3 GSF Use Mask
description: A bitmask specifying which data sources the Gaussian Sum Filter can use.
default_value: 3
range: 0 7
units: 
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 GSF Use Mask (EK3_GSF_USE_MASK)

## Description
`EK3_GSF_USE_MASK` selects the inputs for the emergency yaw estimator.

*   **Bit 0 (1):** Use GPS. (Standard).
*   **Bit 1 (2):** Use Airspeed. (For Planes).

## Tuning & Behavior
*   **Default Value:** 3 (GPS + Airspeed).
*   **Recommendation:** Leave at default.