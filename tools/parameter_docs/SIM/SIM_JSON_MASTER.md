---
layout: parameter
name: SIM_JSON_MASTER
display_name: Simulated JSON Master
description: The IP address of a remote machine running an external physics engine (like Gazebo or AirSim).
default_value: 0
range: 0 4294967295
units: 
group: SIM
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated JSON Master (SIM_JSON_MASTER)

## Description
`SIM_JSON_MASTER` enables the "External Physics" bridge.

Instead of SITL calculating the drone's movements, it can send the motor outputs to a high-fidelity simulator (like **Gazebo**, **AirSim**, or **Webots**) and get the position/sensor data back over a JSON socket. This parameter sets the IP address of that external simulator.

## Tuning & Behavior
*   **Default Value:** 127.0.0.1 (Localhost).
*   **Usage:** Only active if the SITL build includes the JSON backend.