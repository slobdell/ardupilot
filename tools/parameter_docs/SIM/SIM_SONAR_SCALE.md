---
layout: parameter
name: SIM_SONAR_SCALE
display_name: Simulated Sonar Scale
description: The scaling factor (meters per volt) for the simulated analog sonar.
default_value: 12.1212
range: 0 100
units: m/V
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Sonar Scale (SIM_SONAR_SCALE)

## Description
`SIM_SONAR_SCALE` simulates the calibration of an analog rangefinder (like the Maxbotix EZ series).

It defines how many meters of distance are represented by 1 Volt of output.

## Tuning & Behavior
*   **Default Value:** 12.1212 (Standard Maxbotix).
*   **Testing:** Change this to simulate an uncalibrated sensor and verify your `RNGFND1_SCALING` parameter can correct it.