---
layout: parameter
name: BARO_SPEC_GRAV
display_name: Fluid Specific Gravity
description: Sets the density of the fluid for water depth measurement (ArduSub).
default_value: 1.0
range: 0.5 2.0
units: 
group: BARO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro.cpp#L139
---

# Fluid Specific Gravity (BARO_SPEC_GRAV)

## Description
`BARO_SPEC_GRAV` is used by **ArduSub** (underwater ROVs) to calculate depth. 

When a pressure sensor is used underwater, the autopilot translates the pressure into depth based on the density of the water. Fresh water and salt water have different densities, and this parameter allows you to calibrate the depth reading for your specific operating environment.

*   **1.00:** Fresh Water.
*   **1.025:** Standard Salt Water (Sea water).

## The Mathematics
$$ \text{Depth} = \frac{\text{Pressure Difference}}{\rho \times g} $$
where $\rho$ is the water density derived from `BARO_SPEC_GRAV`.

## Tuning & Behavior
*   **Default:** 1.0.
*   **Recommendation:** If you are diving in the ocean, change this to **1.025** for the most accurate depth telemetry.
*   **Note:** This parameter is generally ignored for aerial vehicles.