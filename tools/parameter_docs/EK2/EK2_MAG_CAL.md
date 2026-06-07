---
layout: parameter
name: EK2_MAG_CAL
display_name: Magnetometer default fusion mode
description: Determines when the filter will use the 3-axis magnetometer fusion model.
default_value: 3
range: 0 4
units: 
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Magnetometer default fusion mode (EK2_MAG_CAL)

## Description
Configures the EKF's magnetometer processing logic.

## Tuning & Behavior
*   **Default Value:** 3 (After first climb yaw reset) for Copter, 0 (When flying) for Plane
*   **Values:** 0:When flying, 1:When manoeuvring, 2:Never, 3:After first climb yaw reset, 4:Always
*   **Settings 0, 1, and 3 are standard for most aircraft.**