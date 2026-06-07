---
layout: parameter
name: AHRS_COMP_BETA
display_name: AHRS Velocity Complementary Filter Beta Coefficient
description: This controls the time constant for the cross-over frequency used to fuse AHRS (airspeed and heading) and GPS data to estimate ground velocity. Time constant is 0.1/beta. A larger time constant will use GPS data less and a small time constant will use air data less.
default_value: 0.1
range: 0.001 0.5
units: 
group: AHRS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AHRS/AP_AHRS.cpp
---

# AHRS Velocity Complementary Filter Beta Coefficient (AHRS_COMP_BETA)

## Description
Controls the weighting between GPS data and air data for ground velocity estimation.

## Tuning & Behavior
*   **Default Value:** 0.1
*   **Range:** 0.001 to 0.5
*   **A larger beta value increases reliance on air data (airspeed/heading).**
*   **A smaller beta value increases reliance on GPS data.**
