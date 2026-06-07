---
layout: parameter
name: FAST_SAMPLE
display_name: IMU Fast Sampling Mask
description: Bitmask of IMUs to enable fast sampling on (typically 8kHz or more).
default_value: 0
range: 
units: 
group: FAST
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_InertialSensor/AP_InertialSensor.cpp
---

# IMU Fast Sampling Mask (FAST_SAMPLE)

## Description
Defines which physical IMUs should be sampled at their maximum possible rate (fast sampling). This can significantly improve vibration rejection and overall flight stability but requires more CPU power.
*   **Default Value:** 0 (Standard sampling)
*   **Bitmask corresponds to IMU indices 1 through 7.**