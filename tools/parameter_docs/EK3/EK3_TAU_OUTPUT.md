---
layout: parameter
name: EK3_TAU_OUTPUT
display_name: EKF3 Output Time Constant
description: Time constant (in centiseconds) for the output observer (position/velocity smoothing).
default_value: 25
range: 10 50
units: cs
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Output Time Constant (EK3_TAU_OUTPUT)

## Description
`EK3_TAU_OUTPUT` is the final smoothing filter for the EKF.

The raw EKF state can jump discretely when a GPS update arrives (5Hz or 10Hz). The "Output Observer" smooths these jumps to provide a continuous 400Hz stream to the position controller.

## Tuning & Behavior
*   **Default Value:** 25 (0.25 seconds).
*   **Lower Value:** Faster response, more jitter.
*   **Higher Value:** Smoother, more lag.