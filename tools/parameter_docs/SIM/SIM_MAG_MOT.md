---
layout: parameter
name: SIM_MAG_MOT
display_name: Simulation Compass Motor Interference
description: Simulates the magnetic field distortion caused by motor current (Amps).
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L102
---

# Simulation Compass Motor Interference (SIM_MAG_MOT)

## Description
`SIM_MAG_MOT` simulates "CompassMot" effects.

In real drones, the high-current wires going to the motors produce magnetic fields that can bias the compass. As you increase throttle, the compass heading "twists." This parameter allows you to simulate this effect to test the efficacy of the CompassMot calibration.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Set to **0.5**. Perform a full throttle punch in Loiter. The drone will likely rotate (yaw) unintentionally as the compass drifts under load.