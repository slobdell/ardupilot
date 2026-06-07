---
layout: parameter
name: EK3_FLOW_I_GATE
display_name: EKF3 Flow Innovation Gate
description: The number of standard deviations allowed before an optical flow measurement is rejected.
default_value: 300
range: 100 1000
units: '%'
group: EK3
visual_asset_id: flow_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Flow Innovation Gate (EK3_FLOW_I_GATE)

## Description
`EK3_FLOW_I_GATE` prevents the drone from chasing shadows.

Optical flow sensors can get confused by moving objects or sudden light changes. If the flow sensor reports a movement that is physically impossible given the drone's IMU data, this gate rejects it.

## Tuning & Behavior
*   **Default Value:** 300 (3 Sigma).
*   **Recommendation:** Set to **500** if you fly over high-contrast terrain (like grass/concrete boundaries) that triggers false rejections.