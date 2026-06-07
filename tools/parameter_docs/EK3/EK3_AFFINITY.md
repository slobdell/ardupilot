---
layout: parameter
name: EK3_AFFINITY
display_name: EKF3 Sensor Affinity Options
description: Controls the affinity between sensor instances and EKF cores.
default_value: 0
range: 
units: 
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# EKF3 Sensor Affinity Options (EK3_AFFINITY)

## Description
Advanced configuration to "lock" specific sensors (e.g., GPS2 or Baro3) to specific EKF cores. This allows the system to evaluate independent combinations of hardware sensors.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   Bit 0: EnableGPSAffinity
    *   Bit 1: EnableBaroAffinity
    *   Bit 2: EnableCompassAffinity
    *   Bit 3: EnableAirspeedAffinity
