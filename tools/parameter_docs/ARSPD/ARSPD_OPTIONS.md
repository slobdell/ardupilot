---
layout: parameter
name: ARSPD_OPTIONS
display_name: Airspeed options bitmask
description: Bitmask of options to use with airspeed.
default_value: 11
range: 
units: 
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed.cpp
---

# Airspeed options (ARSPD_OPTIONS)

## Description
Advanced configuration bitmask for airspeed sensor health monitoring and EKF consistency checks.

## Tuning & Behavior
*   **Default Value:** 11 (SpeedMismatchDisable | AllowSpeedMismatchRecovery | UseEkf3Consistency)
*   **Bitmask:**
    *   0: SpeedMismatchDisable (Mark unhealthy on large groundspeed mismatch)
    *   1: AllowSpeedMismatchRecovery (Mark healthy if mismatch resolves)
    *   2: DisableVoltageCorrection
    *   3: UseEkf3Consistency (Require airspeed to match EKF estimated wind)
    *   4: Report cal offset to GCS