---
layout: parameter
name: SOAR_POLAR_CD0
display_name: Zero Lift Drag Coefficient
description: The parasite drag coefficient of the aircraft when lift is zero.
default_value: 0.027
range: 0.005 0.5
units: 
group: SOAR
visual_asset_id: glider_polar_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Soaring/AP_Soaring.cpp#L78
---

# Zero Lift Drag Coefficient (SOAR_POLAR_CD0)

## Description
`SOAR_POLAR_CD0` is a fundamental aerodynamic constant for your glider. It represents the "Parasite Drag" – the air resistance caused by the fuselage, tail, and skin friction when the wing is not producing lift.

ArduSoar uses this (along with `SOAR_POLAR_B` and `K`) to build a mathematical model of how fast your plane sinks at any given airspeed. Without an accurate model, the autopilot cannot distinguish between a "Good Thermal" and the plane simply gliding efficiently.

## The Mathematics
The sink rate ($V_z$) is calculated using the drag polar equation:

$$ V_z = \frac{\text{CD0} \cdot V^3}{K} + \frac{B \cdot K}{V \cdot \cos(\phi)^2} $$

Where:
*   $V$ is airspeed.
*   $K$ is the loading factor.
*   $B$ is the induced drag coefficient.

## Tuning & Behavior
*   **Default Value:** 0.027.
*   **Recommendation:** 
    *   **High Performance Glider:** 0.015 - 0.025.
    *   **Foam Glider (Bixler/Skywalker):** 0.030 - 0.045.
*   **Calibration:** If the drone thinks it's in lift even when the air is perfectly still, your `CD0` is likely set too high (it expects more drag than the plane actually has).