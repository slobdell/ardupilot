---
layout: parameter
name: EK3_FLOW_DELAY
display_name: EKF3 Optical Flow Delay
description: The delay (in ms) of the optical flow data relative to the IMU.
default_value: 10
range: 0 500
units: ms
group: EK3
visual_asset_id: ekf_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Optical Flow Delay (EK3_FLOW_DELAY)

## Description
`EK3_FLOW_DELAY` accounts for the processing lag in your Optical Flow camera (e.g., HereFlow, CX-OF).

Flow sensors calculate motion by comparing image frames, which takes time. If this delay isn't accounted for, the EKF will think the motion happened *now* instead of *10ms ago*, causing instability.

## Tuning & Behavior
*   **Default Value:** 10 ms.
*   **Recommendation:**
    *   **HereFlow:** 10-20 ms.
    *   **PX4Flow:** 10 ms.