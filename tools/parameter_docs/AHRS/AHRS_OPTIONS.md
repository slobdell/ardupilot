---
layout: parameter
name: AHRS_OPTIONS
display_name: Optional AHRS behaviour
description: This controls optional AHRS behaviour, such as EKF/DCM fallback logic.
default_value: 0
range: 
units: 
group: AHRS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AHRS/AP_AHRS.cpp
---

# Optional AHRS behaviour (AHRS_OPTIONS)

## Description
Bitmask for advanced AHRS configuration, primarily controlling fallback logic.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   0: DisableDCMFallbackFW
    *   1: DisableDCMFallbackVTOL
    *   2: DontDisableAirspeedUsingEKF