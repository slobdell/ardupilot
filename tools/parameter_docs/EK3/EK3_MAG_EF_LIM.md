---
layout: parameter
name: EK3_MAG_EF_LIM
display_name: EKF3 Magnetic Earth Field Limit
description: The maximum allowed change (in mGauss) from the expected earth magnetic field.
default_value: 50
range: 0 500
units: mGauss
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Magnetic Earth Field Limit (EK3_MAG_EF_LIM)

## Description
`EK3_MAG_EF_LIM` acts as a sanity check for the compass.

The autopilot knows roughly what the earth's magnetic field *should* look like at your location (based on the WMM table). If the EKF tries to learn a magnetic offset larger than this limit, it assumes the compass is being jammed by a localized magnetic anomaly (like a power line) and rejects the update.

## Tuning & Behavior
*   **Default Value:** 50 mGauss.
*   **Recommendation:** Increase to **100** if you fly in areas with strong magnetic variations (e.g. volcanic soil).