---
layout: parameter
name: AHRS_EKF_TYPE
display_name: Use NavEKF Kalman filter version
description: This controls which NavEKF Kalman filter version is used for attitude and position estimation.
default_value: 3
range: 
units: 
group: AHRS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AHRS/AP_AHRS.cpp
---

# Use NavEKF Kalman filter version (AHRS_EKF_TYPE)

## Description
Selects the primary Extended Kalman Filter (EKF) version for flight estimation.

## Tuning & Behavior
*   **Default Value:** 3 (EKF3)
*   **Values:** 0:Disabled, 2:Enable EKF2, 3:Enable EKF3, 11:ExternalAHRS
*   **EKF3 is the modern standard for ArduPilot.**
