---
layout: parameter
name: EK3_FLOW_M_NSE
display_name: EKF3 Optical Flow Measurement Noise
description: The expected noise (in rad/s) of the optical flow sensor measurements.
default_value: 0.15
range: 0.05 0.5
units: rad/s
group: EK3
visual_asset_id: flow_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Optical Flow Measurement Noise (EK3_FLOW_M_NSE)

## Description
`EK3_FLOW_M_NSE` tells the EKF how "Trustworthy" the flow sensor is.

*   **Low Value:** Trust the flow sensor more. Tighter position hold, but risk of "Toilet Bowling" if the lens is dirty.
*   **High Value:** Trust the IMU more. Smoother flight, but more drift.

## Tuning & Behavior
*   **Default Value:** 0.15 rad/s.