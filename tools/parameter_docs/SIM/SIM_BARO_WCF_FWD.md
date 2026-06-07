---
layout: parameter
name: SIM_BARO_WCF_FWD
display_name: Simulation Barometer Wind Coefficient Forward
description: Simulates the pressure change (error) on the barometer caused by forward airspeed.
default_value: 0
range: -0.1 0.1
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL_Baro.cpp#L45
---

# Simulation Barometer Wind Coefficient Forward (SIM_BARO_WCF_FWD)

## Description
`SIM_BARO_WCF_FWD` simulates "Static Port Error."

On real planes, as the airspeed increases, the pressure around the fuselage drops (Bernoulli's principle). If your barometer isn't perfectly vented, this can cause the drone to think it is climbing when it is actually just speeding up. This parameter allows you to simulate that effect to test compensation algorithms (`BARO_WCF_ENABLE`).

## The Mathematics
The pressure error ($\Delta P$) is calculated as:
$$ \Delta P = \text{WCF} \cdot \frac{1}{2} \cdot \rho \cdot V^2 $$

Where:
*   $V$ is airspeed in the forward direction.
*   $\rho$ is air density.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Set to **0.02**. Fly the drone fast in a straight line. If you see the reported altitude change while you are at a constant height, the simulation is working.
