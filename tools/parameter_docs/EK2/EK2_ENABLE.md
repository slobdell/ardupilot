---
layout: parameter
name: EK2_ENABLE
display_name: Enable EKF2
description: This enables the EKF2 (Extended Kalman Filter version 2) subsystem.
default_value: 0
range: 0 1
units: 
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Enable EKF2 (EK2_ENABLE)

## Description
Global switch to enable the second-generation Extended Kalman Filter. Enabling EKF2 makes the math run in the background, but it is only used for flight control if AHRS_EKF_TYPE is set to 2.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Requires reboot after changing.**
