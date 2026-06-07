---
layout: parameter
name: TECS_SPD_OMEGA
display_name: Speed Estimator Bandwidth
description: The crossover frequency (in rad/s) for the airspeed complementary filter. Controls the mix between the airspeed sensor and longitudinal acceleration.
default_value: 2.0
range: 0.5 5.0
units: rad/s
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L81
---

# Speed Estimator Bandwidth (TECS_SPD_OMEGA)

## Description
`TECS_SPD_OMEGA` determines how fast the autopilot reacts to speed changes.

It blends the **Airspeed Sensor** with the **longitudinal Accelerometer**. 

*   **High Value:** Trust the Airspeed Sensor more. Fast reaction to gusts, but noisy if the sensor isn't well-protected.
*   **Low Value:** Trust the Inertial navigation more. Smooths out "jumps" in airspeed caused by turbulence.

## Tuning & Behavior
*   **Default Value:** 2.0 rad/s.
*   **Recommendation:** Leave at **2.0**.