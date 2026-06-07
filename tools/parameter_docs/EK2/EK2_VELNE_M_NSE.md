---
layout: parameter
name: EK2_VELNE_M_NSE
display_name: GPS horizontal velocity noise
description: Lower limit on the speed accuracy reported by the GPS receiver for horizontal velocity.
default_value: 0.5
range: 0.05 5.0
units: m/s
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# GPS horizontal velocity noise (EK2_VELNE_M_NSE)

## Description
Specifies the expected noise level in the GPS horizontal velocity data. Increasing this value reduces the weighting of GPS velocity measurements in the EKF.

## Tuning & Behavior
*   **Default Value:** 0.5 m/s (Plane/Rover), 0.3 m/s (Copter)
*   **Range:** 0.05 to 5.0 m/s