---
layout: parameter
name: EK3_MAG_CAL
display_name: Magnetometer default fusion mode
description: Determines when the filter will use the 3-axis magnetometer fusion model.
default_value: 3
range: 0 4
units: 
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# Magnetometer default fusion mode (EK3_MAG_CAL)

## Description
Configures the EKF3 magnetometer processing logic. Identical in behavior to EK2_MAG_CAL.

## Tuning & Behavior
*   **Default Value:** 3 (After first climb yaw reset) for Copter, 0 (When flying) for Plane
*   **Values:** 0:When flying, 1:When manoeuvring, 2:Never, 3:After first climb yaw reset, 4:Always