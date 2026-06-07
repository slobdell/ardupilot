---
layout: parameter
name: EK3_ENABLE
display_name: Enable EKF3
description: This enables the EKF3 (Extended Kalman Filter version 3) subsystem.
default_value: 1
range: 0 1
units: 
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# Enable EKF3 (EK3_ENABLE)

## Description
Global switch to enable the third-generation Extended Kalman Filter. ArduPilot defaults to EKF3 for most modern hardware. Enabling it makes the math run; set AHRS_EKF_TYPE to 3 to use it for flight control.

## Tuning & Behavior
*   **Default Value:** 1 (Enabled)
*   **Requires reboot after changing.**
