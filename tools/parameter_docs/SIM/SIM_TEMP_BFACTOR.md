---
layout: parameter
name: SIM_TEMP_BFACTOR
display_name: Simulation Barometer Temperature Factor
description: Scaling factor for pressure change with temperature on the simulated barometer.
default_value: 0.0
range: 0 5
units: 
group: SIM
visual_asset_id: imu_temp_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L142
---

# Simulation Barometer Temperature Factor (SIM_TEMP_BFACTOR)

## Description
`SIM_TEMP_BFACTOR` simulates "Thermal Altitude Drift."

Real pressure sensors (barometers) are slightly affected by temperature. As the flight controller heats up, the reported altitude might "drift" by a few meters even if the drone is sitting still. This parameter simulates that error.

## Tuning & Behavior
*   **Default Value:** 0 (Perfect sensor).
*   **Testing:** Set to **1.2** to simulate a typical ICM-20789 sensor.