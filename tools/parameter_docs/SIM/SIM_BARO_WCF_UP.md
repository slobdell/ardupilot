---
layout: parameter
name: SIM_BARO_WCF_UP
display_name: Simulated Baro Wind Comp Factor Up
description: Pressure change due to wind from the up direction (Pascals per m/s^2).
default_value: 0
range: -10 10
units: Pa/(m/s)^2
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Baro Wind Comp Factor Up (SIM_BARO_WCF_UP)

## Description
`SIM_BARO_WCF_UP` simulates the "Bernoulli Effect" on your static port.

When wind blows across a hole (static port), it creates a pressure drop (or rise), causing the drone to think it is at a different altitude. This parameter defines how much the reported pressure changes when wind hits the drone from the top.

## The Mathematics
$$ \Delta P = C_{up} \times V_{up}^2 $$

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Use **-0.05** to simulate a typical drone where propwash creates a low-pressure zone above the flight controller.