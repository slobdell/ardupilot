---
layout: parameter
name: SIM_TEMP_START
display_name: Simulation Start Temperature
description: The ambient temperature (in degrees Celsius) at the start of the simulation.
default_value: 25.0
range: -20 60
units: degC
group: SIM
visual_asset_id: imu_temp_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L140
---

# Simulation Start Temperature (SIM_TEMP_START)

## Description
`SIM_TEMP_START` sets the initial temperature for SITL sensor thermal models.

ArduPilot simulates "Thermal Warmup." When the simulation starts, the sensors (IMU, Baro) begin at this temperature and gradually heat up towards the internal operating temperature of the flight controller. This is used to test temperature compensation algorithms.

## Tuning & Behavior
*   **Default Value:** 25.0°C.
*   **Testing:** Set to **0.0** to test how your drone handles a cold-start in winter conditions.