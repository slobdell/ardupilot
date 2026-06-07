---
layout: parameter
name: SIM_MAG2_OFS
display_name: Simulation Magnetometer 2 Offset
description: Adds a constant bias offset to the second simulated magnetometer.
default_value: 0
range: -100 100
units: mGauss
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L119
---

# Simulation Magnetometer 2 Offset (SIM_MAG2_OFS)

## Description
`SIM_MAG2_OFS` simulates hard-iron interference on the secondary compass.

This is useful for testing the EKF's ability to handle inconsistent compass data. If Compass 1 is perfect and Compass 2 has a massive offset, the EKF should (ideally) reject Compass 2 or learn the offset.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Set to **100** to simulate a magnetized screw near the second GPS puck.