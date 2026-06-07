---
layout: parameter
name: EK3_RNG_I_GATE
display_name: EKF3 Rangefinder Innovation Gate
description: The number of standard deviations allowed before a rangefinder measurement is rejected.
default_value: 500
range: 100 1000
units: '%'
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Rangefinder Innovation Gate (EK3_RNG_I_GATE)

## Description
`EK3_RNG_I_GATE` filters out Lidar "Glitches."

Lidars often give false readings when flying over grass, water, or bright sunlight. This gate ensures that a sudden jump from 2m to 50m is ignored if the IMU says the drone hasn't moved.

## Tuning & Behavior
*   **Default Value:** 500 (5 Sigma).