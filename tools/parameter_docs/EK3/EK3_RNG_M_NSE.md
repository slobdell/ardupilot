---
layout: parameter
name: EK3_RNG_M_NSE
display_name: EKF3 Rangefinder Measurement Noise
description: The expected noise (in meters) of the rangefinder measurements.
default_value: 0.5
range: 0.1 5.0
units: m
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Rangefinder Measurement Noise (EK3_RNG_M_NSE)

## Description
`EK3_RNG_M_NSE` sets the trust level for the Lidar.

*   **0.1:** Highly trusted. Use for precision landing on flat surfaces.
*   **0.5 (Default):** Standard trust. Good for general flight.
*   **1.0+:** Low trust. Use for sonars or noisy environments.

## Tuning & Behavior
*   **Default Value:** 0.5 m.