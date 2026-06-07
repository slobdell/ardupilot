---
layout: parameter
name: EK3_MAG_MASK
display_name: EKF3 Magnetometer Mask
description: A bitmask specifying which magnetometers should be used for fusion.
default_value: 0
range: 0 255
units: 
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Magnetometer Mask (EK3_MAG_MASK)

## Description
`EK3_MAG_MASK` selects which compasses the EKF is allowed to listen to.

By default (0), the EKF uses the first healthy compass it finds. This mask forces it to use specific sensors.

*   **Bit 0:** Compass 1.
*   **Bit 1:** Compass 2.
*   **Bit 2:** Compass 3.

## Tuning & Behavior
*   **Default Value:** 0 (All).
*   **Recommendation:** If you have an external GPS/Compass and an internal noisy compass, set this to **1** (Bit 0) to force the EKF to only use the external one.