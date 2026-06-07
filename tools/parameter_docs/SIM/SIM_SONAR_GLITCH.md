---
layout: parameter
name: SIM_SONAR_GLITCH
display_name: Simulation Sonar Glitch
description: Adds a constant offset (in meters) to the simulated rangefinder reading to simulate a glitch.
default_value: 0
range: -5 5
units: m
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L122
---

# Simulation Sonar Glitch (SIM_SONAR_GLITCH)

## Description
`SIM_SONAR_GLITCH` simulates a "bad bounce" or sensor error.

Rangefinders often report incorrect distances when flying over grass or water. This parameter allows you to inject sudden jumps in the reported altitude to test the EKF's rejection logic or the terrain following safety limits.
