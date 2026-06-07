---
layout: parameter
name: SIM_MAG1_OFS
display_name: Simulation Magnetometer 1 Offset
description: Adds a constant bias offset to the first simulated magnetometer.
default_value: 0
range: -100 100
units: mGauss
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L104
---

# Simulation Magnetometer 1 Offset (SIM_MAG1_OFS)

## Description
`SIM_MAG1_OFS` simulates "Hard Iron" interference.

Hard iron effects are caused by static magnetic fields on the drone (like a magnetized screw or the metal frame). This offsets the magnetic reading in a constant direction. This is what you are calibrating when you perform the "Compass Dance."

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Set to **50**. The drone will report "Compass Variance" until you perform a compass calibration in SITL.