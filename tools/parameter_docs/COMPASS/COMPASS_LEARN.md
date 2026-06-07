---
layout: parameter
name: COMPASS_LEARN
display_name: Learn compass offsets automatically
description: Enable or disable the automatic learning of compass offsets.
default_value: 0
range: 0 3
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Learn compass offsets automatically (COMPASS_LEARN)

## Description
Enables the "Compass Learning" feature where the flight controller refines the sensor offsets in-flight by analyzing the magnetometer data as the vehicle rotates.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Values:** 0:Disabled, 1:Internal-Learning, 2:EKF-Learning, 3:InFlight-Learning
*   **Useful for refining a coarse initial calibration, but should generally be disabled once offsets have stabilized.**
