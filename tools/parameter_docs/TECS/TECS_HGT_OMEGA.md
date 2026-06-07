---
layout: parameter
name: TECS_HGT_OMEGA
display_name: Height Estimator Bandwidth
description: The crossover frequency (in rad/s) for the height complementary filter. Controls the mix between barometric and inertial altitude.
default_value: 3.0
range: 1.0 10.0
units: rad/s
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L76
---

# Height Estimator Bandwidth (TECS_HGT_OMEGA)

## Description
`TECS_HGT_OMEGA` determines how much the autopilot trusts its sensors for altitude.

ArduPlane calculates its climb rate by blending the **Barometer** (slow but stable) with the **Accelerometers** (fast but drifty).

*   **High Value (e.g. 5.0):** Trusts the Barometer more. Good if your IMU is vibey.
*   **Low Value (e.g. 1.0):** Trusts the IMU more. Provides instantaneous climb rate detection. Better for high-performance acrobatics.

## Tuning & Behavior
*   **Default Value:** 3.0 rad/s.
*   **Recommendation:** Leave at **3.0**. Only increase if you see the plane "ballooning" (pitching up) during rapid acceleration due to EKF height spikes.