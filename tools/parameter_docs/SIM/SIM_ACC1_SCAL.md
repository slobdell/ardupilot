---
layout: parameter
name: SIM_ACC1_SCAL
display_name: Simulation Accelerometer 1 Scale
description: Adds a scale factor error to the first simulated accelerometer.
default_value: 0
range: -0.1 0.1
units: 
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L125
---

# Simulation Accelerometer 1 Scale (SIM_ACC1_SCAL)

## Description
`SIM_ACC1_SCAL` simulates a "Sensitivity Error."

If an accelerometer is perfectly calibrated, it should report exactly 9.81 m/s/s when facing down. A scale error means it might report 9.90 or 9.70 instead. 

*   **0 (Default):** Perfect scale.
*   **0.05:** 5% scale error.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Use to verify the effectiveness of the 6-point Accel Calibration routine.