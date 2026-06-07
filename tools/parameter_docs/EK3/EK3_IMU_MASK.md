---
layout: parameter
name: EK3_IMU_MASK
display_name: Bitmask of active IMUs
description: 1 byte bitmap of IMUs to use in EKF3. A separate instance of EKF3 will be started for each IMU selected.
default_value: 3
range: 
units: 
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# Bitmask of active IMUs (EK3_IMU_MASK)

## Description
Defines which physical IMUs will have an associated EKF3 core instance. Running multiple cores provides redundancy; the flight controller will automatically switch to the healthiest core.

## Tuning & Behavior
*   **Default Value:** 3 (IMU1 and IMU2)
*   **Bitmask Examples:** 1:IMU1 only, 3:IMU1 & IMU2, 7:IMU1, IMU2 & IMU3.
*   **Requires reboot to take effect.**