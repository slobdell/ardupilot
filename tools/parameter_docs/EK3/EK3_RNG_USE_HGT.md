---
layout: parameter
name: EK3_RNG_USE_HGT
display_name: EKF3 Rangefinder Use Height
description: The percentage of the rangefinder's max range below which it can be used as the primary height source.
default_value: -1
range: -1 70
units: '%'
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Rangefinder Use Height (EK3_RNG_USE_HGT)

## Description
`EK3_RNG_USE_HGT` allows the EKF to automatically switch to Lidar altitude when close to the ground.

If set to 70%, and your Lidar has a 10m range, the EKF will switch from Baro to Lidar when you descend below 7 meters. This provides terrain following for landing without needing to change `EK3_SRC1_POSZ`.

## Tuning & Behavior
*   **-1 (Default):** Disabled. Lidar is only used if `EK3_SRCx_POSZ` = 2 (Rangefinder).
*   **0-70:** Enabled. Percentage of `RNGFND_MAX_CM`.