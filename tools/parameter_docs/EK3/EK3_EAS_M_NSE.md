---
layout: parameter
name: EK3_EAS_M_NSE
display_name: EKF3 Airspeed Measurement Noise
description: The expected noise (in m/s) of the airspeed sensor measurements.
default_value: 1.4
range: 0.5 5.0
units: m/s
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Airspeed Measurement Noise (EK3_EAS_M_NSE)

## Description
`EK3_EAS_M_NSE` defines how "Clean" the airspeed signal is.

*   **1.4 (Default):** Standard for analog pitot tubes.
*   **Lower Value:** Trusts the airspeed sensor more. Use for high-quality digital sensors (MS4525).
*   **Higher Value:** Trusts the IMU/GPS more. Use for noisy sensors or turbulent conditions.

## Tuning & Behavior
*   **Default Value:** 1.4 m/s.